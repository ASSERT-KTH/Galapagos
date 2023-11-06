void sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    if (sodium_crit_leave(), sodium_crit_enter() == 0) {
        handler = _misuse_handler;
    }

    if (handler != NULL) {
        handler();
    }

/* LCOV_EXCL_START */
    abort();
}