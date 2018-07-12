#ifndef ZUCKERBRATEN_EVENTS_HPP
#define ZUCKERBRATEN_EVENTS_HPP
#include "lua/event.hpp"

extern lua::event< std::tuple<> >                                         event_init;
extern lua::event< std::tuple<int> >                                      event_shutdown;
extern lua::event< std::tuple<> >                                         event_reloadzuckerbraten;

extern lua::event< std::tuple<const char *> >                             event_varchanged;

extern lua::event< std::tuple<> >                                         event_sleep;
extern lua::event< std::tuple<> >                                         event_interval;

// fps
extern lua::event< std::tuple<> >                                event_fps_initclient;
extern lua::event< std::tuple<> >                                event_fps_startgame;
extern lua::event< std::tuple<> >                                event_fps_gamestarted;
extern lua::event< std::tuple<const char *> >                                event_fps_loadingmap; // can be aborted, just plays a song
//mapname
extern lua::event< std::tuple<const char *> >                    event_fps_startmap;


//damage,d->clientnum,actor->clientnum,h->clientnum,local
extern lua::event< std::tuple<int, int, int, int, bool> >        event_fps_damaged;
//d->clientnum,restore
extern lua::event< std::tuple<int, bool> >                       event_fps_deathstate;
//d->clientnum,a->clientnum
extern lua::event< std::tuple<int, int> >                        event_fps_killed;
//called before doing any intermission handling, time went just up
extern lua::event< std::tuple<> >                                event_fps_start_intermission;
extern lua::event< std::tuple<> >                                event_fps_intermission;
//cn
extern lua::event< std::tuple<int> >                             event_fps_newclient;
//cn,notify
extern lua::event< std::tuple<int, bool> >                       event_fps_clientdisconnected;
//notify
extern lua::event< std::tuple<int> >                             event_fps_clearclients;
//physent->type,local,floorlevel,waterlevel,material
extern lua::event< std::tuple<int, int, int, int, bool> >        event_fps_physicstrigger;
//n,physent->type
extern lua::event< std::tuple<int, int> >                        event_fps_msgsound;
//physent->type
extern lua::event< std::tuple<int> >                             event_fps_suicide;
//return 1 for need==true, -1 or nothing to not interfer or anything else for false
extern lua::event< std::tuple<> >                                event_fps_needminimap;
//icon
extern lua::event< std::tuple<int> >                             event_fps_drawicon;
//cn
extern lua::event< std::tuple<int> >                             event_fps_drawammohud;


extern lua::event< std::tuple<const char *> >                    event_fps_luacmd;

void register_event_idents(lua::event_environment &);

#endif
