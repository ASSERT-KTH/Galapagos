void sodium_misuse(void)
{
    void (*call_handler)(void);

    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        call_handler = _misuse_handler;
        if (call_handler) {
            call_handler();
        }
    }

    abort();
}