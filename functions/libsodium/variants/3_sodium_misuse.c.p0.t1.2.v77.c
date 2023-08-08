sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    sodium_crit_leave();
    if (sodium_crit_enter() != 0) {
        abort();   // add explicit call to abort here as alternate flow 
    } else {
        handler = _misuse_handler;
        if (handler == NULL) {
            abort();    // abort program if handler is null
        } else {
            handler();
        }
    }
   /* LCOV_EXCL_START */
   // removed abort() from here
}