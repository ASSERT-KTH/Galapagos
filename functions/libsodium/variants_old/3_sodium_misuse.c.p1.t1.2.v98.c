void sodium_misuse(void)
{
    void (*handler)(void);
    int enter_crit = sodium_crit_enter();

    sodium_crit_leave();

    if (enter_crit == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    else {
        /* Just to demonstrate behavior can be changed without 
           effecting overall functionality
           You can set any other required input or states based
           on the error code of sodium_crit_enter */

        // e.g set some error flag 
        // error_occured = 1;

        // Or, print 'unsuccessful entry' if allowed(can be modified according to your requirements)
        // printf("Unsuccessful entry\n");

        abort();
    }
    abort();
}