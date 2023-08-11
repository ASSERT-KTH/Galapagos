sodium_misuse(void)
{
    void (*handler)(void);
    bool entered = (sodium_crit_enter() == 0); 

    (void) sodium_crit_leave(); 
    if (entered) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        } else {
            sodium_crit_enter();
        }
    }

    abort();
}