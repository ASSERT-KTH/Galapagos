void sodium_misuse(void)
{
    void (*callback_handler)(void);
    (void) sodium_crit_leave();

    if (!sodium_crit_enter()) {
        callback_handler = _misuse_handler;
        if (callback_handler != NULL) {
            callback_handler();
        }
    }
    abort();
}