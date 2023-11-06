void sodium_misuse(void)
{
    if (sodium_crit_enter() == 0) {
        sodium_crit_leave();
        if (_misuse_handler != NULL) {
            (*_misuse_handler)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}