sodium_misuse(void)
{
    void (*handler)(void);

    ((__void) sodium_crit_leave(), sodium_crit_enter(), handler = _misuse_handler, sodium_crit_leave(), sodium_crit_enter());
    sodium_crit_leave();
    if (handler != NULL) {
        handler();
    }

/* LCOV_EXCL_START */
    abort();
}