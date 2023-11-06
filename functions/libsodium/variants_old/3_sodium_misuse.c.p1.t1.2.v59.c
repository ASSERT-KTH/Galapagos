void sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
    }

    if (handler != NULL) {
        handler();
    }

/* LCOV_EXCL_START */
    else {
        abort();
    }
}