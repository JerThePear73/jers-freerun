CURR_ROMHACK = "sm64"
for i in pairs(gActiveMods) do
    local mod = gActiveMods[i]
    if mod.incompatible then
        if mod.incompatible:find("romhack") then
            CURR_ROMHACK = mod.name
        end
    end
    if mod.category then
        if mod.category:find("romhack") then
            CURR_ROMHACK = mod.name
        end
    end
    CURR_ROMHACK = CURR_ROMHACK:gsub("\\(.-)\\", "")
    CURR_ROMHACK = CURR_ROMHACK:gsub('%W','')
    CURR_ROMHACK = CURR_ROMHACK:gsub('v%d+','')
    CURR_ROMHACK = CURR_ROMHACK:lower()
end

function timestamp(frames)
    if type(frames) ~= "number" then return "x:xx:x" end
    local seconds = math.round(frames) / 30
    local minutes = math.floor(seconds / 60)
    local milliseconds = math.floor((seconds - math.floor(seconds)) * 10)
    seconds = math.floor(seconds % 60)
    return minutes > 0 and string.format("%d:%02d.%01d", minutes, seconds, milliseconds) or string.format("%01d.%01d", seconds, milliseconds)
end

function num_to_hex(num)
    num = math.round(num)
    if num == 0 then
        return '0'
    end
    local neg = false
    if num < 0 then
        neg = true
        num = num * -1
    end
    local hexstr = "0123456789ABCDEF"
    local result = ""
    while num > 0 do
        local n = (num%16)
        result = string.sub(hexstr, n + 1, n + 1) .. result
        num = math.floor(num / 16)
    end
    result = '0x'..result
    if neg then
        result = '-' .. result
    end
    return result
end

function network_player_get_name_color(np)
    local capColor = network_player_get_override_palette_color(np, CAP)
    return "\\#"..string.gsub(num_to_hex(127 + capColor.r*0.5), "0x", "")..string.gsub(num_to_hex(127 + capColor.g*0.5), "0x", "")..string.gsub(num_to_hex(127 + capColor.b*0.5), "0x", "").."\\"
end