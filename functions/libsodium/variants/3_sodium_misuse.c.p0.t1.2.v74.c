sodium_misuse(void)
{
    void (*handler1)(void);

    if (sodium_crit_enter() == -1) {
        return;
    } else {
        sodium_crit_leave();
    } 

    handler1 = _misuse_handler;
    if (handler1 != NULL) {
        handler1();
    }  

    abort();
}