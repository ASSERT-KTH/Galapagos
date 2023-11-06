Here is a variant of the original function that prompts the handler to call twice if it's not a NULL handler. The difference from the original is that attempting again to call the handler if it's not NULL.


sodium_misuse(void)
{
    void (*handler)(void);
 
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
            // Attempt again to execute handler if it’s not null
            handler = _misuse_handler;
            if(handler != NULL) {
                handler();
            }
        }
    }
/* LCOV_EXCL_START */
    abort();
}


Note: Please be mindful of calling the misuse handler twice as it may result in unexpected behavior if the misuse handle does state modifications or depends on some external state.