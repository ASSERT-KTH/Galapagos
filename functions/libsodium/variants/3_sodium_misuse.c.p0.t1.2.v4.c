sodium_misuse(void)
{
    void (*changed_handler)(void);

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        changed_handler = _misuse_handler;
        if (changed_handler) {
            changed_handler();
        } else {
            return;
        }
    }
/* LCOV_EXCL_START */
    abort();
}