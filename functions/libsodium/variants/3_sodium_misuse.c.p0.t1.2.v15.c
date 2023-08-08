sodium_misuse(void)
{
    void (*derived_handler)(void) = NULL;

    sodium_crit_leave();
    if (!sodium_crit_enter()) {
        derived_handler = _misuse_handler;
        if (derived_handler) {
            derived_handler();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
/* LCOV_EXCL_END */
}