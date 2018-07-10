#ifndef ZUCKERBRATEN_EVENTS_HPP
#define ZUCKERBRATEN_EVENTS_HPP
#include "lua/event.hpp"

extern lua::event< std::tuple<> >                                         event_init;
extern lua::event< std::tuple<> >                                         event_started;
extern lua::event< std::tuple<int> >                                      event_shutdown;
extern lua::event< std::tuple<> >                                         event_reloadzuckerbraten;

extern lua::event< std::tuple<const char *> >                             event_varchanged;

extern lua::event< std::tuple<> >                                         event_sleep;
extern lua::event< std::tuple<> >                                         event_interval;

// fps
extern lua::event< std::tuple<int, int, int, int, int, bool> >        event_fps_damaged;

extern lua::event< std::tuple<const char *> >        event_fps_luacmd;

void register_event_idents(lua::event_environment &);

#endif
