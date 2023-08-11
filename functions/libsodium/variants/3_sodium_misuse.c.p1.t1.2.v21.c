sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
}
/* LCOV_EXCL_START */
    abort();
}