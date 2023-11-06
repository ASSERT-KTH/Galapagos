sodium_misuse(void)
{
    void (*nulltest_handler)(void) = NULL;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        nulltest_handler = _misuse_handler;
        if (nulltest_handler) {
            nulltest_handler();
        } else {
            if(nulltest_handler == NULL) return;
        }
    }
/* LCOV_EXCL_START */
    abort();
}