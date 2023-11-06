sodium_misuse(void)
{
    void (*misuse_handler)(void);

    misuse_handler = _misuse_handler;
    (void) sodium_crit_leave();
    if ((sodium_crit_enter() == 0) && (misuse_handler != NULL)) {
        misuse_handler();
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
}