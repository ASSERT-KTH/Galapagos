This variant adds extra handling for cases where `_misuse_handler` is `NULL`, setting a default function to be used as the handler before eventually aborting:


sodium_misuse(void)
{
    void (*handler)(void); 

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        } else {
            //Extra handling for cases where misuse_handler is NULL
            handler = []() { /* Default handling code here */ };
            handler();
        }        
    }
/* LCOV_EXCL_START */
    abort();
}
