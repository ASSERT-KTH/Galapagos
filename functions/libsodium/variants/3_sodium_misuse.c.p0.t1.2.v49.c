sodium_misuse(void)
{
    void (*handler)(void);
    
    int ret = sodium_crit_enter();
    (void) sodium_crit_leave();
    
    if (ret == 0) {
        if (_misuse_handler != NULL) {
            handler = _misuse_handler;
            handler();
        }
    }
    
    while(1) {}
}