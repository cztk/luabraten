#ifndef CLIENT_EXTAPI_HPP
#define CLIENT_EXTAPI_HPP

extern "C"{
#include <luajit-2.0/lua.h>
}

#include <string>
#include <vector>

namespace game {

    void logConsole(int, const char *);
    void luacmd(const char *);
 
}

#endif
