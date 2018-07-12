#include "lua/event.hpp"

lua::event< std::tuple<> >                                         event_init("init");

lua::event< std::tuple<int> >                                      event_shutdown("shutdown");
lua::event< std::tuple<> >                                         event_reloadzuckerbraten("reloadzuckerbraten");

lua::event< std::tuple<const char *> >                             event_varchanged("varchanged");

lua::event< std::tuple<> >                                         event_sleep("sleep");
lua::event< std::tuple<> >                                         event_interval("interval");

// fps

lua::event< std::tuple<> >                                event_fps_initclient("fps_initclient");
lua::event< std::tuple<> >                                event_fps_startgame("fps_startgam");
lua::event< std::tuple<> >                                event_fps_gamestarted("fps_gamestarted");
lua::event< std::tuple<const char *> >                                event_fps_loadingmap("fps_loadingmap"); // can be aborted, just plays a song
//mapname
lua::event< std::tuple<const char *> >                    event_fps_startmap("fps_startmap");


//damage,d->clientnum,actor->clientnum,h->clientnum,local
lua::event< std::tuple<int, int, int, int, bool> >        event_fps_damaged("fps_damaged");
//d->clientnum,restore
lua::event< std::tuple<int, bool> >                       event_fps_deathstate("fps_deathstate");
//d->clientnum,a->clientnum
lua::event< std::tuple<int, int> >                        event_fps_killed("fps_killed");
//called before doing any intermission handling, time went just up
lua::event< std::tuple<> >                                event_fps_start_intermission("fps_start_intermission");
lua::event< std::tuple<> >                                event_fps_intermission("fps_intermission");
//cn
lua::event< std::tuple<int> >                             event_fps_newclient("fps_newclient");
//cn,notify
lua::event< std::tuple<int, bool> >                       event_fps_clientdisconnected("fps_clientdisconnected");
//notify
lua::event< std::tuple<int> >                             event_fps_clearclients("fps_clearclients");
//physent->type,local,floorlevel,waterlevel,material
lua::event< std::tuple<int, int, int, int, bool> >        event_fps_physicstrigger("fps_physicstrigger");
//n,physent->type
lua::event< std::tuple<int, int> >                        event_fps_msgsound("fps_msgsound");
//physent->type
lua::event< std::tuple<int> >                             event_fps_suicide("fps_suicide");
//return 1 for need==true, -1 or nothing to not interfer or anything else for false
lua::event< std::tuple<> >                                event_fps_needminimap("fps_needminimap");
//icon
lua::event< std::tuple<int> >                             event_fps_drawicon("fps_drawicon");
//cn
lua::event< std::tuple<int> >                             event_fps_drawammohud("fps_drawammohud");

lua::event< std::tuple<const char *> >                         event_fps_luacmd("fps_luacmd");




void register_event_idents(lua::event_environment & env)
{
    lua::event_base * events[] = {
      & event_init,
      & event_shutdown,
      & event_reloadzuckerbraten,

      &event_varchanged,

      & event_sleep,
      & event_interval,

& event_fps_initclient,
& event_fps_startgame,
& event_fps_gamestarted,
& event_fps_loadingmap,
& event_fps_startmap,
& event_fps_damaged,
& event_fps_deathstate,
& event_fps_killed,
& event_fps_start_intermission,
& event_fps_intermission,
& event_fps_newclient,
& event_fps_clientdisconnected,
& event_fps_clearclients,
& event_fps_physicstrigger,
& event_fps_msgsound,
& event_fps_suicide,
& event_fps_needminimap,
& event_fps_drawicon,
& event_fps_drawammohud,
& event_fps_luacmd,

      NULL
    };

    env.register_event_idents(events);
}
