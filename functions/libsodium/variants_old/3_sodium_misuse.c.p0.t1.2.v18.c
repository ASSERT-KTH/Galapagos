sodium_misuse(void)
{
    void (*tmp_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 0) {
        return;
    }
    tmp_handler = _misuse_handler;
    if (tmp_handler != NULL) {
        tmp_handler();
    }
/* LCOV_EXCL_START */
    abort();
}