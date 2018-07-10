#include "../engine/engine.h"

template<typename FunctionPointerType>
static void bind_function(lua_State * L, int table, const char * name, FunctionPointerType function)
{
    lua_pushstring(L, name);
    lua::push_function(L, function);
    lua_settable(L, table);
}

static void bind_function(lua_State * L, int table, const char * name, lua_CFunction function)
{
    lua_pushstring(L, name);
    lua_pushcfunction(L, function);
    lua_settable(L, table);
}

void bind_core_functions(lua_State * L, int T)
{
    bind_function(L, T, "reload_lua", reload_zuckerbraten);

    bind_function(L, T, "file_exists", file_exists);
    bind_function(L, T, "dir_exists", dir_exists);

    bind_function(L, T, "sleep", lua::sleep);
    bind_function(L, T, "interval", lua::interval);
    bind_function(L, T, "cancel_timer", lua::cancel_timer);

    bind_function(L, T, "log_event_error", log_event_error);

    extern int get_lua_stack_size();
    bind_function(L, T, "lua_stack_size", get_lua_stack_size);

    bind_function(L, T, "enet_time_set", enet_time_set);
    bind_function(L, T, "enet_time_get", (int (*)())enet_time_get);

    bind_function(L, T, "revision", zuckerbraten::revision);
    bind_function(L, T, "version", zuckerbraten::build_date);
    bind_function(L, T, "build_date", zuckerbraten::build_date);
    bind_function(L, T, "build_time", zuckerbraten::build_time);

    #include "core_client_functions.hpp"

}
