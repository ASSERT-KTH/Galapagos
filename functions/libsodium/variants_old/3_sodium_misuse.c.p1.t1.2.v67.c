
sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
            return;
        }
    }
    else {
        /* Handle the exception situation when sodium_crit_enter() does not return 0. */ 
        /* This behavior was undefined in the original function but it is 
            defined in this variant by calling abort() in this special case. */
        abort();
    }
    
    /* By arriving here we are sure that sodium_crit_enter() has returned 0 but _misuse_handler was NULL.*/
    abort();
}
