void sodium_misuse(void)
{
    void (*handler)(void);
    handler = _misuse_handler;

    if (sodium_crit_enter() == 0 && handler != NULL) {
        (void) sodium_crit_leave();
        handler();
    } else {
        /* LCOV_EXCL_START */
        abort();
    }
}