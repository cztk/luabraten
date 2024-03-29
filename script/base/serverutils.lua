local _ = require "underscore"
local crypto = require "crypto"

--! @brief the mins function calculates <value> in minutes to milliseconds
--! @param value integer
--! @return return integer
function braten.mins(value)
    return value * 1000 * 60
end

--! @brief the secs function calculates <value> in seconds to milliseconds
--! @param value integer
--! @return return integer
function braten.secs(value)
    return value * 1000
end

--! @brief the coloured_text function returns a color formatted text snippet or starting code block if no text given. valid codes are 0-7,green,blue,yellow,red,grey,magenta,orange,white
--! @param colour_code integer
--! @param text string optional
--! @return return string
function coloured_text(colour_code, text)
    if text then
        return "\fs\f" .. colour_code .. text .. "\fr"
    else
        return "\fs\f" .. colour_code
    end
end

green    = _.curry(coloured_text, 0)
blue     = _.curry(coloured_text, 1)
yellow   = _.curry(coloured_text, 2)
red      = _.curry(coloured_text, 3)
grey     = _.curry(coloured_text, 4)
magenta  = _.curry(coloured_text, 5)
orange   = _.curry(coloured_text, 6)
white    = _.curry(coloured_text, 7)

-- Copied from http://lua-users.org/wiki/SimpleRound
function math.round(num, idp)
  local mult = 10^(idp or 0)
  return math.floor(num * mult + 0.5) / mult
end
round = math.round

function pack(...)
    return {...}
end

function catch_error(chunk, ...)
    
    local pcall_results = {pcall(chunk, ...)}
    
    if not pcall_results[1] then
        braten.log_error(pcall_results[2])
    end
    
    return pcall_results
end

function braten.hashpassword(cn, password)
    return crypto.tigersum(string.format("%i %i %s", cn, server.player_sessionid(cn), password))
end

function _if(expr, true_value, false_value)
    if expr then
        return true_value
    else
        return false_value
    end
end

setfenv = setfenv or function(f, t)
    f = (type(f) == 'function' and f or debug.getinfo(f + 1, 'f').func)
    local name
    local up = 0
    repeat
        up = up + 1
        name = debug.getupvalue(f, up)
    until name == '_ENV' or name == nil
    if name then
        debug.upvaluejoin(f, up, function() return name end, 1)  -- useunique upvalue
        debug.setupvalue(f, up, t)
    end
end 

dofile("./script/base/utils/apps.lua")
dofile("./script/base/utils/file.lua")
if not server.is_authserver then dofile("./script/base/utils/gamemode.lua") end
dofile("./script/base/utils/mysql.lua")
dofile("./script/base/utils/string.lua")
dofile("./script/base/utils/table.lua")
dofile("./script/base/utils/validate.lua")
dofile("./script/base/utils/deferred.lua")
dofile("./script/base/utils/event_emitter.lua")
dofile("./script/base/utils/network.lua")
