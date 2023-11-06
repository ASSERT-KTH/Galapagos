void sodium_misuse(void)
{
    void (*handler)(void);
    volatile int condition = sodium_crit_enter();

    (void) sodium_crit_leave();
    if (condition == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    } 
    else {
	/* Do nothing. You can execute some other behavior, if you need */
    }

    if (condition == 0) {
	abort();
    }
}