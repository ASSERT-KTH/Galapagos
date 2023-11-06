sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    int result = sodium_crit_enter();
    if (result == 0) {
        handler = _misuse_handler;
    }
    else {
        abort();
    }
    if (handler != NULL) {
        handler();
    }
/* LCOV_EXCL_START */
    abort();
}