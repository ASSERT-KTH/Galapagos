sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        handler = _misuse_handler;
        if (handler) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
/* LCOV_EXCL_END */
}