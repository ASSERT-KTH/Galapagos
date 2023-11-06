sodium_misuse(void)
{
    void (*handler)(void);
    int sodium_flag;

    sodium_flag = sodium_crit_enter();
    (void) sodium_crit_leave();

    if (sodium_flag == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    else {
        abort();
   }    
}