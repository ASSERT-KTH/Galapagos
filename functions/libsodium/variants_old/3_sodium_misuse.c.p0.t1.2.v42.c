sodium_misuse(void)
{
    void (*pureHandler)(void);

    if (sodium_crit_enter() == 0) {
        sodium_crit_leave();
        pureHandler = _misuse_handler;
        if (pureHandler != NULL) {
            pureHandler();
        }
    }
    else {
        abort();
    }
}