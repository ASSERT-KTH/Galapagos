sodium_misuse(void)
{
    void (*handler)(void);
 
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            sodium_crit_leave();
            handler();
        }
    }
    else {
        (void) sodium_crit_leave();
        handler();
    }
         
    // exit the program if handler is NULL.   
    if(handler == NULL) {
        /* LCOV_EXCL_START */
        abort();
    }
}