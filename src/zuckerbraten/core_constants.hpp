template<int Constant>
static int get_constant(lua_State * L)
{
    if(lua_gettop(L)) luaL_error(L, "cannot set constant");
    lua_pushinteger(L, Constant);
    return 1;
}


void bind_core_constants(lua_State * L, int T)
{
// game.h
    bind_function(L, T, "CON_CHAT", get_constant<int(CON_CHAT)>);
    bind_function(L, T, "CON_TEAMCHAT", get_constant<int(CON_TEAMCHAT)>);
    bind_function(L, T, "CON_GAMEINFO", get_constant<int(CON_GAMEINFO)>);
    bind_function(L, T, "CON_FRAG_SELF", get_constant<int(CON_FRAG_SELF)>);
    bind_function(L, T, "CON_FRAG_OTHER", get_constant<int(CON_FRAG_OTHER)>);
    bind_function(L, T, "CON_TEAMKIL", get_constant<int(CON_TEAMKILL)>);

    bind_function(L, T, "DISC_NONE", get_constant<DISC_NONE>);
    bind_function(L, T, "DISC_EOP", get_constant<DISC_EOP>);
    bind_function(L, T, "DISC_LOCAL", get_constant<DISC_LOCAL>);
    bind_function(L, T, "DISC_KICK", get_constant<DISC_KICK>);
    bind_function(L, T, "DISC_MSGERR", get_constant<DISC_MSGERR>);
    bind_function(L, T, "DISC_IPBAN", get_constant<DISC_IPBAN>);
    bind_function(L, T, "DISC_PRIVATE", get_constant<DISC_PRIVATE>);
    bind_function(L, T, "DISC_MAXCLIENTS", get_constant<DISC_MAXCLIENTS>);
    bind_function(L, T, "DISC_TIMEOUT", get_constant<DISC_TIMEOUT>);
    bind_function(L, T, "DISC_OVERFLOW", get_constant<DISC_OVERFLOW>);
    bind_function(L, T, "DISC_NUM", get_constant<DISC_NUM>);

    bind_function(L, T, "PRIV_NONE", get_constant<PRIV_NONE>);
    bind_function(L, T, "PRIV_MASTER", get_constant<PRIV_MASTER>);
    bind_function(L, T, "PRIV_AUTH", get_constant<PRIV_AUTH>);
    bind_function(L, T, "PRIV_ADMIN", get_constant<PRIV_ADMIN>);

    bind_function(L, T, "GREEN_ARMOUR", get_constant<A_GREEN>);
    bind_function(L, T, "YELLOW_ARMOUR", get_constant<A_YELLOW>);

    bind_function(L, T, "ALIVE", get_constant<CS_ALIVE>);
    bind_function(L, T, "DEAD", get_constant<CS_DEAD>);
    bind_function(L, T, "SPAWNING", get_constant<CS_SPAWNING>);
    bind_function(L, T, "LAGGED", get_constant<CS_LAGGED>);
    bind_function(L, T, "SPECTATOR", get_constant<CS_SPECTATOR>);
    bind_function(L, T, "EDITING", get_constant<CS_EDITING>);

    bind_function(L, T, "MM_OPEN", get_constant<MM_OPEN>);
    bind_function(L, T, "MM_VETO", get_constant<MM_VETO>);
    bind_function(L, T, "MM_LOCKED", get_constant<MM_LOCKED>);
    bind_function(L, T, "MM_PRIVATE", get_constant<MM_PRIVATE>);
    bind_function(L, T, "MM_PASSWORD", get_constant<MM_PASSWORD>);
}

