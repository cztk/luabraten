braten = {}

local properties = core.vars

setmetatable(braten,{
    
    __index = function(table, key)
        
        local value = core[key]
        
        if not value then
            value = properties[key]
            if type(value) == "function" then
                value = value()
            end
        end
        
        return value
    end,
    
    __newindex = function(table, key, value)
        
        local existing_property = properties[key]
        
        if existing_property and type(existing_property) == "function" then
            existing_property(value)
        else
            core[key] = value
        end
    end
});

braten.event_handler = event_listener.add
braten.cancel_handler = event_listener.remove
braten.cancel_handlers = event_listener.clear_all
braten.create_event_signal = event_listener.create_event
braten.cancel_event_signal = event_listener.destroy_event

