sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() != 0) {
        (void) sodium_crit_leave();
    } else {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }

    if(handler == NULL) {    
        abort();
    }
}