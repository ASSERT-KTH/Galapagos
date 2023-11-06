void sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        handler = _misuse_handler;
        if (handler) {
            (*handler)();
        }
    }
    for (;;) {
        abort();
    }
}