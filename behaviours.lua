local CHECKPOINT_ACT_READY      = 0
local CHECKPOINT_ACT_INTERACTED = 1
local CHECKPOINT_ACT_WAITING    = 2
local CHECKPOINT_ACT_NEXT       = 3
local CHECKPOINT_ACT_NEXT_NEXT  = 4

local function bhv_checkpoint_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.hitboxRadius = 250
    o.hitboxHeight = 1000
    o.oOpacity = 0
    o.oAction = CHECKPOINT_ACT_READY
end
local function bhv_checkpoint_loop(o)
    local m = gMarioStates[0]
    local e = gFreerunStates[m.playerIndex]
    local g = gGlobalSyncTable

    if e.frChkpt == o.oBehParams then
        o.oAction = CHECKPOINT_ACT_READY
    elseif e.frChkpt + 1 == o.oBehParams then
        o.oAction = CHECKPOINT_ACT_NEXT
    elseif e.frChkpt + 2 == o.oBehParams then
        o.oAction = CHECKPOINT_ACT_NEXT_NEXT
    elseif e.frChkpt - 1 == o.oBehParams then
        o.oAction = CHECKPOINT_ACT_INTERACTED
    else
        o.oAction = CHECKPOINT_ACT_WAITING
    end

    if obj_check_hitbox_overlap(m.marioObj, o) and o.oAction == CHECKPOINT_ACT_READY then
        o.oOpacity = 255
        audio_sample_play(SOUND_FREERUN_CHECKPOINT, m.pos, 1)
        e.frChkpt = e.frChkpt + 1
        if e.frChkpt == #freerunCourses[gGlobalSyncTable.frMap].courses[gGlobalSyncTable.frCourse] + 1 then
            if e.frCurrLap < g.frLaps then
                e.frChkpt = 0
                e.frCurrLap = e.frCurrLap + 1
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, m.marioObj.header.gfx.cameraToObject)
            else
                audio_sample_play(SOUND_FREERUN_FINISH, m.pos, 1.5)
            end
        end
        o.oTimer = 0
    end

    if o.oAction == CHECKPOINT_ACT_INTERACTED then
        o.oOpacity = o.oOpacity * 0.8
        if o.oTimer > 15 then
            o.oAction = CHECKPOINT_ACT_WAITING
        end
    elseif o.oAction == CHECKPOINT_ACT_WAITING then
        o.oOpacity = 0
    elseif o.oAction == CHECKPOINT_ACT_READY then
        o.oOpacity = 150 + math.sin(o.oTimer*0.2)*50
    elseif o.oAction == CHECKPOINT_ACT_NEXT then
        o.oOpacity = 80
    elseif o.oAction == CHECKPOINT_ACT_NEXT_NEXT then
        o.oOpacity = 40
    end
end
id_bhvFreerunCheckpoint = hook_behavior(nil, OBJ_LIST_GENACTOR, false, bhv_checkpoint_init, bhv_checkpoint_loop, "bhvFreerunCheckpoint")

local function bhv_player_arrow_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    cur_obj_hide()
end
local function bhv_player_arrow_loop(o)
    local m = gMarioStates[0]
    local chkpt = get_checkpoint_from_action(CHECKPOINT_ACT_READY)

    if chkpt ~= nil then
        cur_obj_unhide()
        o.oFaceAngleYaw     = obj_angle_to_object(o, chkpt)
        o.oFaceAnglePitch   = obj_pitch_to_object(o, chkpt)
        obj_scale(o, math.clamp((dist_between_objects(o, chkpt)/1000) + 1, 1, 2.5))
    else
        cur_obj_hide()
    end

    o.oPosX = m.pos.x
    o.oPosY = m.pos.y + 250
    o.oPosZ = m.pos.z
end
id_bhvFreerunPlayerArrow = hook_behavior(nil, OBJ_LIST_UNIMPORTANT, false, bhv_player_arrow_init, bhv_player_arrow_loop, "bhvFreerunPlayerArrow")

local function bhv_checkpoint_arrow_init(o)
    local m = gMarioStates[0]
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oPosX = m.pos.x
    o.oPosY = m.pos.y + 250
    o.oPosZ = m.pos.z
end
local function bhv_checkpoint_arrow_loop(o)
    local m = gMarioStates[0]
    local e = gFreerunStates[m.playerIndex]
    local g = gGlobalSyncTable
    local pointed_chkpt = get_checkpoint_from_action(CHECKPOINT_ACT_NEXT)
    local active_chkpt = get_checkpoint_from_action(CHECKPOINT_ACT_READY)
    local lerpRate = 0.05

    if active_chkpt ~= nil then
        cur_obj_unhide()
        o.oPosX = math.lerp(o.oPosX, active_chkpt.oPosX, lerpRate)
        o.oPosY = math.lerp(o.oPosY, active_chkpt.oPosY + 250, lerpRate)
        o.oPosZ = math.lerp(o.oPosZ, active_chkpt.oPosZ, lerpRate)
        if pointed_chkpt ~= nil then
            obj_set_model_extended(o, E_MODEL_FREERUN_CHECKPOINT_ARROW)
            o.oFaceAngleYaw = obj_angle_to_object(o, pointed_chkpt)
            o.oFaceAnglePitch = obj_pitch_to_object(o, pointed_chkpt)
        else
            if e.frCurrLap >= g.frLaps then
                obj_set_model_extended(o, E_MODEL_FREERUN_FLAG_FINISH)
            else
                obj_set_model_extended(o, E_MODEL_FREERUN_FLAG_LAP)
            end
            o.oFaceAngleYaw = o.oFaceAngleYaw + 0x500
            o.oFaceAnglePitch = 0
        end
    else
        cur_obj_hide()
    end

    obj_scale(o, 3)
end
id_bhvFreerunCheckpointArrow = hook_behavior(nil, OBJ_LIST_UNIMPORTANT, false, bhv_checkpoint_arrow_init, bhv_checkpoint_arrow_loop, "bhvFreerunCheckpointArrow")