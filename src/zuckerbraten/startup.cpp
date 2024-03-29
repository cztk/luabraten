#include "zuckerbraten.hpp"
#include "utils/files.hpp"
#include "cube.h"

#include "extsrc/fpsgame/fps_functions.hpp"
#include "extsrc/fpsgame/client_functions.hpp"

//#include <asio.hpp>

//asio::io_service & get_main_io_service();

#include <iostream>
#include <thread>



bool reloaded = false;

//static std::thread::id main_thread;
/**
    Initializes everything in hopmod. This function is called at server startup and server reload.
*/
void init_zuckerbraten()
{
    //main_thread = std::this_thread::get_id();

    #ifdef STANDALONE
    temp_file_printf("log/zucker_serv.pid", "%i\n", getpid());
    #else
    temp_file_printf("log/zucker_client.pid", "%i\n", getpid());
    #endif

    init_lua();

    static const char * INIT_SCRIPT = "script/zuckerbraten/init.lua";


    lua_State * L = get_lua_state();
    if(luaL_loadfile(L, INIT_SCRIPT) == 0)
    {
        event_listeners().add_listener("init"); // Take the value of the top of the stack to add
        // to the init listeners table
    }
    else
    {
        std::cerr<<"error during initialization: "<<lua_tostring(L, -1)<<std::endl;
        lua_pop(L, 1);
    }

    event_init(event_listeners(), std::make_tuple());
}

void signal_shutdown(int val)
{
    shutdown_lua();
    delete_temp_files_on_shutdown(val);
}

static void reload_zuckerbraten_now()
{
    event_reloadzuckerbraten(event_listeners(), std::make_tuple());

    reloaded = true;

    event_shutdown(event_listeners(), std::make_tuple(static_cast<int>(SHUTDOWN_RELOAD)));

    signal_shutdown(SHUTDOWN_RELOAD);

    init_zuckerbraten();
    std::cout<<"-> Reloaded Zuckerbraten."<<std::endl;

    reloaded = false;
}

void reload_zuckerbraten()
{
    //get_main_io_service().post(reload_zuckerbraten_now);
}
