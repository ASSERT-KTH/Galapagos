sodium_misuse(void)
{
    void (*handler_ptr)(void);
 
    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        handler_ptr = _misuse_handler;
        if (handler_ptr) {
            (*handler_ptr)();
        }
    }
    /* LCOV_EXCL_START */
    while(1) {
        abort();
    }
}
