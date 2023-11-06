void sodium_misuse(void)
{
    void (*misuse_handler)(void);

    sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        
        misuse_handler = _misuse_handler;
        
        if (misuse_handler) {
            (*misuse_handler)();
        }
    }

    abort();
}