E_MODEL_FREERUN_CHECKPOINT = smlua_model_util_get_id('jers_freerun_checkpoint_geo')
E_MODEL_FREERUN_PLAYER_ARROW = smlua_model_util_get_id('jers_freerun_arrow_geo')
E_MODEL_FREERUN_CHECKPOINT_ARROW = smlua_model_util_get_id('jers_freerun_arrow_simple_geo')
E_MODEL_FREERUN_FLAG_FINISH = smlua_model_util_get_id('jers_freerun_flag_finish_geo')
E_MODEL_FREERUN_FLAG_LAP = smlua_model_util_get_id('jers_freerun_flag_lap_geo')

SOUND_FREERUN_CHECKPOINT = audio_sample_load("jers_freerun_checkpoint.ogg")
SOUND_FREERUN_FINISH = audio_sample_load("jers_freerun_finish.ogg")
MUSIC_FREERUN_0 = audio_stream_load("jers_freerun_music_0.ogg")
local BITRATE = 32000
audio_stream_set_loop_points(MUSIC_FREERUN_0, BITRATE * 4.728, BITRATE * 39.740)
audio_stream_set_looping(MUSIC_FREERUN_0, true)

ACT_FREERUN_DECIDING = allocate_mario_action(ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)

gGlobalSyncTable.frMenuOpen = false
gGlobalSyncTable.frMenuOffset = 0
gGlobalSyncTable.frMenuOptions = 0
gGlobalSyncTable.frMap = 0
gGlobalSyncTable.frCourse = 0
gGlobalSyncTable.frLaps = 1
gGlobalSyncTable.builderMode = false

local freerunAct = 73
local stickCooldown = 10
local stickThreshold = 25

gFreerunStates = {}
for i = 0, (MAX_PLAYERS - 1) do
    gFreerunStates[i] = {
        freerunIsActive = false,
        freerunTimer = 0,
        frChkpt = 0,
        frCurrLap = 0,
        frMenuStickCooldown = 0,
        createdChkpt = 0,
    }
end

local function act_freerun_deciding(m)
    local e = gFreerunStates[m.playerIndex]
    local g = gGlobalSyncTable
    set_mario_animation(m, MARIO_ANIM_RUNNING_UNUSED)
    smlua_anim_util_set_animation(m.marioObj, "jers_freerun_anim_thinking")
    m.marioBodyState.eyeState = MARIO_EYES_LOOK_UP
    local mSoun = m.marioObj.header.gfx.cameraToObject
    g.frMap = math.clamp(g.frMap, 0, #freerunCourses)
    g.frCourse = math.clamp(g.frCourse, 0, #freerunCourses[g.frMap].courses)
    g.frLaps = math.clamp(g.frLaps, 1, 5)

    if m.playerIndex == 0 then
        if m.controller.stickY < -stickThreshold and g.frMenuOptions < 3 and e.frMenuStickCooldown == 0 then
            g.frMenuOptions = g.frMenuOptions + 1
            play_sound(SOUND_MENU_EXIT_A_SIGN, mSoun)
            e.frMenuStickCooldown = stickCooldown
        elseif m.controller.stickY > stickThreshold and g.frMenuOptions > 0 and e.frMenuStickCooldown == 0 then
            g.frMenuOptions = g.frMenuOptions - 1
            play_sound(SOUND_MENU_EXIT_A_SIGN, mSoun)
            e.frMenuStickCooldown = stickCooldown
        end
        if g.frMenuOptions >= 0 and g.frMenuOptions < 3 then
            if m.controller.stickX > stickThreshold and e.frMenuStickCooldown == 0 then
                if g.frMenuOptions == 0 and g.frMap < #freerunCourses then
                    g.frMap = g.frMap + 1
                elseif g.frMenuOptions == 1 and g.frCourse < #freerunCourses[g.frMap].courses then
                    g.frCourse = g.frCourse + 1
                elseif g.frMenuOptions == 2 and g.frLaps < 5 then
                    g.frLaps = g.frLaps + 1
                end
                play_sound(SOUND_MENU_EXIT_A_SIGN, mSoun)
                e.frMenuStickCooldown = stickCooldown
            elseif m.controller.stickX < -stickThreshold and e.frMenuStickCooldown == 0 then
                if g.frMenuOptions == 0 and g.frMap > 0 then
                    g.frMap = g.frMap - 1
                elseif g.frMenuOptions == 1 and g.frCourse > 0 then
                    g.frCourse = g.frCourse - 1
                elseif g.frMenuOptions == 2 and g.frLaps > 1 then
                    g.frLaps = g.frLaps - 1
                end
                play_sound(SOUND_MENU_EXIT_A_SIGN, mSoun)
                e.frMenuStickCooldown = stickCooldown
            end
        end

        if g.frMenuOptions == 3 and m.input & INPUT_A_PRESSED ~= 0 then
            if not g.builderMode then
                e.freerunIsActive = true
                warp_to_level(freerunCourses[g.frMap].map, 1, freerunAct)
                network_send(true, {[0] = 1})
            else
                warp_to_level(freerunCourses[g.frMap].map, 1, 0)
            end
        end

        if e.frMenuStickCooldown > 0 then
            e.frMenuStickCooldown = e.frMenuStickCooldown - 1
            if m.controller.stickY == 0 and m.controller.stickX == 0 then
                e.frMenuStickCooldown = 0
            end
        end
    end

    if m.input & INPUT_B_PRESSED ~= 0 then
        set_mario_action(m, ACT_IDLE, 0)
    end
end
hook_mario_action(ACT_FREERUN_DECIDING, act_freerun_deciding)

local function on_packet_recieve(data)
    local g = gGlobalSyncTable
    if data[0] == 1 then
        djui_chat_message_create("packet recieved")
        warp_to_level(freerunCourses[g.frMap].map, 1, freerunAct)
    end
end
hook_event(HOOK_ON_PACKET_RECEIVE, on_packet_recieve)

---@param act integer The action to stop looking for checkpoints once found
---@returns Object
function get_checkpoint_from_action(act)
    local chkpt = obj_get_first_with_behavior_id(id_bhvFreerunCheckpoint)

    while chkpt ~= nil do
        if chkpt.oAction == act then
            return chkpt
        end
        chkpt = obj_get_next_with_same_behavior_id(chkpt)
    end
end

local function freerun_render_hud()
    djui_hud_set_resolution(RESOLUTION_N64)
    local m = gMarioStates[0]
    local e = gFreerunStates[m.playerIndex]
    local np = gNetworkPlayers[m.playerIndex]
    local g = gGlobalSyncTable
    local oscCol = math.abs(math.sin(get_global_timer()*0.3)*255)
    local width = djui_hud_get_screen_width()

    if g.frMenuOffset > 1 then
        local x = width - g.frMenuOffset
        local y = 34
        djui_hud_set_color(0, 0, 0, 150)
        djui_hud_render_rect(x, y, 85, 64)
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text("Freerunning", x + 10, y, 0.5)
        djui_hud_render_rect(x + 8, y + 16, 60, 1)
        local optionsX = x + 16
        djui_hud_print_text("Map: "..freerunCourses[g.frMap].name, optionsX, y + 20, 0.25)
        djui_hud_print_text("Course: "..tostring(g.frCourse + 1), optionsX, y + 30, 0.25)
        djui_hud_print_text("Laps: "..tostring(g.frLaps), optionsX, y + 40, 0.25)
        djui_hud_print_text("Start! ", optionsX, y + 50, 0.25)

        djui_hud_print_text(">", x + 8, y + 20 + (g.frMenuOptions * 10), 0.25)
    end
    g.frMenuOffset = math.lerp(g.frMenuOffset, g.frMenuOpen and 84 or 0, 0.2)

    if e.freerunIsActive and not (_G.charSelect and _G.charSelect.is_menu_open()) then
        gHudDisplay.flags = gHudDisplay.flags & ~HUD_DISPLAY_COINS
        gHudDisplay.flags = gHudDisplay.flags & ~HUD_DISPLAY_STARS

        djui_hud_set_font(FONT_RECOLOR_HUD)
        djui_hud_set_color(255, 255, 255, 255)
        if e.frChkpt == (#freerunCourses[g.frMap].courses[g.frCourse] + 1) then
            djui_hud_set_color(oscCol, oscCol, 0, 255)
        end

        local timerSec = math.floor(e.freerunTimer/30) > 9 and tostring(math.floor(e.freerunTimer/30)) or "0"..tostring(math.floor(e.freerunTimer/30))
        local timerMil = (e.freerunTimer*2 % 60) > 9 and tostring(e.freerunTimer*2 % 60) or "0"..tostring(e.freerunTimer*2 % 60)
        local freerunTimerDisplay = timerSec..":"..timerMil
        djui_hud_print_text(freerunTimerDisplay, djui_hud_get_screen_width() - 78, 34, 1)

        djui_hud_set_font(FONT_HUD)
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text(tostring(e.frChkpt).."/"..tostring(#freerunCourses[gGlobalSyncTable.frMap].courses[gGlobalSyncTable.frCourse] + 1), width - 62 - (#tostring(e.frChkpt) * 12), 54, 1)
        djui_hud_print_text("LAP", width - 58, 74, 0.5)
        djui_hud_print_text(tostring(e.frCurrLap).."/"..tostring(g.frLaps), width - 64 - (#tostring(e.frCurrLap) * 18), 84, 1.5)
    end
end
hook_event(HOOK_ON_HUD_RENDER_BEHIND, freerun_render_hud)

local function freerun_init(type, level, area, node)
    local m = gMarioStates[0]
    local e = gFreerunStates[m.playerIndex]
    local np = gNetworkPlayers[m.playerIndex]
    local g = gGlobalSyncTable

    if np.currActNum ~= freerunAct then
        e.freerunIsActive = false
        if np.currLevelNum ~= LEVEL_CASTLE_GROUNDS and not g.builderMode then
            warp_to_start_level()
        end
    end

    audio_stream_stop(MUSIC_FREERUN_0)
    e.frChkpt = 0
    e.frCurrLap = 1
    e.freerunTimer = 0
    if e.freerunIsActive and m.playerIndex == 0 then
        for i=0, #freerunCourses[g.frMap].courses[g.frCourse] do
            local chkpt_pos = freerunCourses[g.frMap].courses[g.frCourse][i]
            spawn_non_sync_object(id_bhvFreerunCheckpoint, E_MODEL_FREERUN_CHECKPOINT, chkpt_pos.x, chkpt_pos.y, chkpt_pos.z, function(o)
                o.oBehParams = i
            end)
        end
        spawn_non_sync_object(id_bhvFreerunPlayerArrow, E_MODEL_FREERUN_PLAYER_ARROW, 0, 0, 0, nil)
        spawn_non_sync_object(id_bhvFreerunCheckpointArrow, E_MODEL_FREERUN_CHECKPOINT_ARROW, 0, 0, 0, nil)
    end
end
hook_event(HOOK_ON_LEVEL_INIT, freerun_init)

local function freerun_loop()
    local m = gMarioStates[0]
    local e = gFreerunStates[m.playerIndex]
    local g = gGlobalSyncTable
    local vol = ((_G.charSelectExists and _G.charSelect.is_menu_open()) and 0) or ((is_game_paused() or m.action == ACT_STAR_DANCE_EXIT) and 0) or 0.8
    if e.freerunIsActive then
        play_cap_music(0)
        audio_stream_play(MUSIC_FREERUN_0, false, vol)
    else
        audio_stream_stop(MUSIC_FREERUN_0)
    end
end
hook_event(HOOK_UPDATE, freerun_loop)

---@param m MarioState
local function mario_update(m)
    local e = gFreerunStates[m.playerIndex]
    local np = gNetworkPlayers[m.playerIndex]
    local g = gGlobalSyncTable
    if e.freerunIsActive then
        if is_player_active(m) and e.frChkpt ~= (#freerunCourses[g.frMap].courses[g.frCourse] + 1) and (
            m.action ~= ACT_SPAWN_SPIN_AIRBORNE and
            m.action ~= ACT_SPAWN_SPIN_LANDING and
            m.action ~= ACT_SPAWN_NO_SPIN_AIRBORNE and
            m.action ~= ACT_SPAWN_NO_SPIN_LANDING
        ) then
            e.freerunTimer = e.freerunTimer + 1
        end
    end
    if m.action == ACT_IDLE and network_is_server() and m.controller.buttonPressed & Y_BUTTON ~= 0 and not e.freerunIsActive then
        set_mario_action(m, ACT_FREERUN_DECIDING, 0)
        --e.freerunIsActive = not e.freerunIsActive
        --warp_to_level(np.currLevelNum, 1, np.currActNum)
    end

    if g.builderMode and m.playerIndex == 0 and network_is_server() then
        -- thank you saul :)
        if m.controller.buttonPressed & X_BUTTON ~= 0 then
            local posx = "x = " .. tostring(math.floor(m.pos.x) .. ", ")
            local posy = "y = " .. tostring(math.floor(m.pos.y) .. ", ")
            local posz = "z = " .. tostring(math.floor(m.pos.z))
            spawn_non_sync_object(id_bhvStaticObject, E_MODEL_TRANSPARENT_STAR, m.pos.x, m.pos.y, m.pos.z, nil)
            mod_storage_save("("..tostring(e.createdChkpt)..")", "{" .. posx .. posy .. posz .. "},")
            djui_chat_message_create("\\#ff0\\Checkpoint placed!")
            e.createdChkpt = e.createdChkpt + 1
        elseif m.controller.buttonPressed & Y_BUTTON ~= 0 then
            djui_chat_message_create("\\#0ff\\Checkpoints Reset!")
            e.createdChkpt = 0
            mod_storage_clear()
        end
    end
end
hook_event(HOOK_MARIO_UPDATE, mario_update)

local function mario_set_action(m)
    local g = gGlobalSyncTable

    if network_is_server() and m.playerIndex == 0 then
        if m.action == ACT_FREERUN_DECIDING then
            play_sound(SOUND_MENU_CAMERA_ZOOM_IN, m.marioObj.header.gfx.cameraToObject)
            g.frMenuOpen = true
        elseif g.frMenuOpen then
            play_sound(SOUND_MENU_CAMERA_ZOOM_OUT, m.marioObj.header.gfx.cameraToObject)
            g.frMenuOpen = false
        end
    end
end
hook_event(HOOK_ON_SET_MARIO_ACTION, mario_set_action)

---@param m MarioState
---@param o Object
---@param type InteractionType
local function freerun_stars(m, o, type)
    if type == INTERACT_STAR_OR_KEY then
        return false
    end
end
hook_event(HOOK_ALLOW_INTERACT, freerun_stars)

hook_chat_command("build-mode", "- toggle freerun track builder mode. X to save positions. Won't kick you out of levels.", function(msg)
    local g = gGlobalSyncTable
    if not network_is_server() then
		djui_chat_message_create("\\#ffaaaa\\Only the host may use this command")
	else
		g.builderMode = not g.builderMode
	    if g.builderMode then
            djui_chat_message_create("Build mode: ON")
		else
            djui_chat_message_create("Build mode: OFF")
		end
	end
	return true
end)