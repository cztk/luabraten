void luacmd(const char * cmd) {
    event_fps_luacmd(event_listeners(), std::make_tuple(cmd));
}
COMMAND(luacmd, "s");

void logConsole(int contype, const char * text) {
    conoutf(contype, "%s", text);
}
