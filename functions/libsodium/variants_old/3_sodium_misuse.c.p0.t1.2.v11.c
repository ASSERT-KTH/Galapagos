sodium_misuse(void)
{
    void (*otherHandler)(void);

    (void) sodium_crit_leave();
    if(sodium_crit_enter() == 0) {
        otherHandler = _misuse_handler;
        if (otherHandler != NULL) {
            otherHandler();
        }
    }
/* LCOV_EXCL_START */
    sodium_crit_leave();
    if(sodium_crit_enter() != 0) {
        abort();
    }
}