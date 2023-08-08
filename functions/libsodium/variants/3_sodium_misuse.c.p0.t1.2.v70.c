sodium_misuse(void)
{
    void (*handler)(void);
    int rc = sodium_crit_enter();
    (void) sodium_crit_leave();
        
    if ( rc == 0 ) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }

    else {
        abort();
    }
}