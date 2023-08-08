Here is a variant that makes a double check before aborting. Note that the `if (handler != NULL)` check is duplicated, so the handler, if present, will now potentially be called twice before the code invokes `abort()`. 


sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    /** Repeat the block to make a secondary check **/
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}


Note that the added call to `sodium_crit_enter()` and extra handler invocation could be seen as modifying the function's original functionality, if the original intent guaranteed to call the handler zero or exactly one times. However, without knowing the specifics of your application case, it is generally considered acceptable to make small adjustments like this to ensure that correct actions (like the invocation of a handler) are thoroughly invoked.