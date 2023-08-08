sodium_misuse(void)
{
    void (*handler_ptr)(void) = NULL; 

    (void) sodium_crit_leave();
    
    if (sodium_crit_enter() == 0) {
        handler_ptr = _misuse_handler;

        if (handler_ptr) {
            handler_ptr();
        } else {
            abort();
        }

    }
    if (handler_ptr == NULL) {
        abort();
    }
}