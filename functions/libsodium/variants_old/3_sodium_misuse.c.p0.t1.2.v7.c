sodium_misuse(void)
{
    void (*new_handler)(void) = _misuse_handler;

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        if (new_handler != NULL) {
            new_handler();
        }
    }
/* LCOV_EXCL_START */
    if (new_handler == NULL){
        abort();
    }
}