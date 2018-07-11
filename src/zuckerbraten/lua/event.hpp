#ifndef HOPMOD_LUA_EVENT_HPP
#define HOPMOD_LUA_EVENT_HPP

#include "push_function.hpp"
#include "error_handler.hpp"
#include "pcall.hpp"
#include <cassert>
#include <iostream>

namespace lua{

class event_base
{
public:
    event_base(const char * text_id, int numeric_id = -1);
    const char * text_id()const;
    int numeric_id()const;
    static int assign_numeric_id();
private:
    const char * m_text_id;
    int m_numeric_id;
};

class event_environment
{
public:
    event_environment(lua_State *, void (* log_error_function)(const char *) = NULL);
    event_environment();
    bool is_ready();
    void register_event_idents(event_base **);
    lua_State * push_listeners_table(const char * text_id, int num_id);
    void log_error(const char * text_id, const char * message);
    void add_listener(const char * event_id);
    void add_listener(const char * event_id, lua_CFunction);
    void clear_listeners(const event_base &);
    lua_State * lua_state();
private:
    lua_State * m_state;
    int m_text_id_index;
    int m_numeric_id_index;
    void (* m_log_error_function)(const char *);
};

template<typename Tuple>
class event:public event_base
{
public:
    event(const char * text_id, int numeric_id = -1)
     :event_base(text_id, numeric_id)
    {
        
    }
    int prevent_default = -1;

    int operator()(event_environment & environment, const Tuple & args)
    {
        int returnvalue = prevent_default;
        if(environment.is_ready() == false) return returnvalue;
        
        lua_State * L = environment.push_listeners_table(text_id(), numeric_id());
        assert(L && lua_type(L, -1) == LUA_TTABLE);
        
        lua::get_error_handler(L);
        int error_function = lua_gettop(L);
        
        lua_pushvalue(L, -2);
        
        lua_pushnil(L);
        while (lua_next(L, -2) != 0)
        {
            if(lua_type(L, -1) == LUA_TFUNCTION)
            {
                lua::push(L, args);
                if(lua::pcall(L, std::tuple_size<Tuple>::value, 1, error_function) == 0)
                    returnvalue = lua_tonumber(L, -1);
                else 
                    environment.log_error(text_id(), lua_tostring(L, -1));
            }
            lua_pop(L, 1);
        }
        
        lua_pop(L, 3);
        
        return returnvalue;
    }
};

} //namespace lua

#endif
