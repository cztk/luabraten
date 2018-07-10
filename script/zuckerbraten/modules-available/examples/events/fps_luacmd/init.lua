local function load_code(code, environment)
    if setfenv and loadstring then
        local f = assert(loadstring(code))
        setfenv(f,environment)
        return f
    else
        return assert(load(code, nil,"t",environment))
    end
end

local context = {}
context.game = game
-- etc. add libraries/functions that are safe for your application.
-- see: http://lua-users.org/wiki/SandBoxes

local function fps_luacmd(code)
  local ret = load_code("return " .. code, context)
  ret()
end

braten.event_handler("fps_luacmd", fps_luacmd)
