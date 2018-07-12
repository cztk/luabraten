local function fps_needminimap()
    braten.log_status("lua::  fps_needminimap")
    return -5
end

braten.event_handler("fps_needminimap", fps_needminimap)
