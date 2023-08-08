void sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() != 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            sodium_crit_leave();
            handler();
            return;
        }
    }
  
    (void) sodium_crit_leave();
    abort();
}