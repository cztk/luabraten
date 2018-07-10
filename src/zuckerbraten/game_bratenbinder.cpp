using namespace luabridge;
using namespace game;

void conoutf_ns(int type, const char *s)  {
  conoutf(type, s);
}
void conoutf_s(const char *s)  {
  conoutf("\f1%s", s);
}

void luabridge_game(lua_State * L) {

#define addArray(T)\
         beginClass<T>(#T)\
            .addFunction("__arrayindex", &T::__arrayindex)\
            .addFunction("__arraynewindex", &T::__arraynewindex)\
.endClass()

getGlobalNamespace(L).beginNamespace("game")
    .addFunction("conoutf_s", &conoutf_s)
    .addFunction("printname", &game::printname)
.endNamespace();

}
