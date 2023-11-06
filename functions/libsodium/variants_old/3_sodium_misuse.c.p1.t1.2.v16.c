void sodium_misuse(void) {
    void (*handler)(void);

    (void) sodium_crit_leave();

    handler = _misuse_handler; // directly get the handler
    if (handler != NULL) {
        if(sodium_crit_enter() == 0) { // switch place of sodium_crit_enter
            handler();
        }
    }
    
    abort();
}