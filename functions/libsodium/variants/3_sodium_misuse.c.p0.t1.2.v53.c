sodium_misuse(void)
{
    void (*pHandler)(void);

    (void) sodium_crit_leave();

    if (!sodium_crit_enter()) {
        pHandler = _misuse_handler;
        if (pHandler) {
            pHandler();
        }
    }
    else
    {
        return;
    }

    abort();
}