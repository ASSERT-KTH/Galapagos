sodium_misuse(void)
{
    void (*local_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != -1) {
        local_handler = _misuse_handler;
        if (local_handler != NULL) {
            local_handler();
        } else {
            return;
        }
    }

/* LCOV_EXCL_START */
    abort();
}