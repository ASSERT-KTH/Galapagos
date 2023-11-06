sodium_misuse(void)
{
    void (*new_handler)(void) = NULL;

    (void) sodium_crit_leave();

    if (!sodium_crit_enter()) {
        new_handler = _misuse_handler;

        if (new_handler) {
            new_handler();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
}