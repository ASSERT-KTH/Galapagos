sodium_misuse(void)
{
    void (*handler)(void); 

    int is_succ = sodium_crit_enter();
    sodium_crit_leave();
    if (is_succ == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
    } 
    abort();
}