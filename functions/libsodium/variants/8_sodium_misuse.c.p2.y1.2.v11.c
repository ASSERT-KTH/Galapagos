void sodium_misuse(void)
{   
    int result;
    void (*handler)(void);

    (void) sodium_crit_leave();

    result = sodium_crit_enter();
    if (result == 0) {
        handler = _misuse_handler;
    } 

    if (handler != NULL && result == 0) {
        handler();
    }

    abort(); 
}