sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter()) {
        abort();
    } else {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
            return;
        }        
    }
    abort();
}