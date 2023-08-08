sodium_misuse(void)
{   
    void (*handler)(void) = NULL;

    sodium_crit_leave();
    (void) sodium_crit_enter();

    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
           (*handler)();
        }   
    } else {
        abort();
    } 

/* LCOV_EXCL_START */
    if (handler == NULL) {
        abort();
    }
}