local _ = require "underscore"

local filename = "client"
local admin_filename = "admin"

local logfile = io.open("log/" .. filename .. ".log","a+")

function braten.log(msg)
    assert(msg ~= nil)
--    if not braten.is_authserver then msg = braten.filtertext(msg) end
    logfile:write(os.date("[%a %d %b %X] ",os.time()))
    logfile:write(msg)
    logfile:write("\n")
    logfile:flush()
end

local admin_logfile = io.open("log/" .. admin_filename .. ".log","a+")

function braten.admin_log(msg)
    assert(msg ~= nil)
--    if not braten.is_authserver then msg = braten.filtertext(msg) end
    admin_logfile:write(os.date("[%a %d %b %X] ",os.time()))
    admin_logfile:write(msg)
    admin_logfile:write("\n")
    admin_logfile:flush()
end

braten.event_handler("shutdown", _.curry(logfile.close, logfile))
braten.event_handler("shutdown", _.curry(admin_logfile.close, admin_logfile))

function braten.log_status(msg)
    print(msg)
end
    
function braten.log_error(error_message)
    if type(error_message) == "table" and type(error_message[1]) == "string" then
       error_message = error_message[1]
    end

    io.stderr:write(os.date("[%a %d %b %X] ",os.time()))
    io.stderr:write(error_message)
    io.stderr:write("\n")
    io.stderr:flush()
end
