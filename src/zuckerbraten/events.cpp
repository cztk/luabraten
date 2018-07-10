#include "lua/event.hpp"

lua::event< std::tuple<> >                                         event_init("init");
lua::event< std::tuple<> >                                         event_started("started");
lua::event< std::tuple<int> >                                      event_shutdown("shutdown");
lua::event< std::tuple<> >                                         event_reloadzuckerbraten("reloadzuckerbraten");

lua::event< std::tuple<const char *> >                             event_varchanged("varchanged");

lua::event< std::tuple<> >                                         event_sleep("sleep");
lua::event< std::tuple<> >                                         event_interval("interval");

// fps
lua::event< std::tuple<int, int, int, int, int, bool> >        event_fps_damaged("fps_damaged");

lua::event< std::tuple<const char *> >                         event_fps_luacmd("fps_luacmd");

void register_event_idents(lua::event_environment & env)
{
    lua::event_base * events[] = {
      & event_init,
      & event_started,
      & event_shutdown,
      & event_reloadzuckerbraten,

      &event_varchanged,

      & event_sleep,
      & event_interval,

      & event_fps_damaged,

      &event_fps_luacmd,

      NULL
    };

    env.register_event_idents(events);
}
