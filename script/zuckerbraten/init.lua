package.path = package.path .. ";script/package/?.lua;"
package.cpath = package.cpath .. ";lib/lib?.so"

local fsutils = require "filesystem_utils"
execfilename = "clientexec"

add_exec_search_path = fsutils.add_exec_search_path
find_script = fsutils.find_script
exec = fsutils.exec
pexec = fsutils.pexec
exec_if_found = fsutils.exec_if_found
eval_lua = fsutils.eval_lua

add_exec_search_path("conf")
add_exec_search_path("script")
add_exec_search_path("script/zuckerbraten")
script_base_dir = "script/base"

exec(script_base_dir .. "/pcall.lua")
exec(script_base_dir.."/event.lua")
exec(script_base_dir.."/braten.lua")
exec(script_base_dir.."/ffi.lua")
exec(script_base_dir .. "/logging_base.lua")
exec(script_base_dir.."/exec.lua")
exec(script_base_dir.."/utils.lua")
exec(script_base_dir.."/tables.lua")

braten.modules_avail_dir = "./script/zuckerbraten/modules-available"
braten.modules_enabled_dir = "./script/zuckerbraten/modules-enabled"
exec(script_base_dir.."/module.lua")

exec_if_found("conf/client_conf.lua")


braten.event_handler("fps_gamestarted", function()
    braten.log_status("meep meep")
end)

braten.event_handler("shutdown", function()
    braten.log_status("Server shutting down.")
end)

braten.log('waiting');
