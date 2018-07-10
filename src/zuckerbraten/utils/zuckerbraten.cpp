#include "utils/zuckerbraten.hpp"

namespace zuckerbraten{

int revision()
{
#if defined(REVISION) && (REVISION + 0)
    return REVISION;
#endif
    return -1;
}

const char * build_date()
{
    return __DATE__;
}

const char * build_time()
{
    return __TIME__;
}

}
