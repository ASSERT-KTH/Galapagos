sodium_misuse(void)
{
    void (*handler)(void);
    int status = sodium_crit_enter();
  
    (void) sodium_crit_leave();

    if (status == 0) {
        handler = _misuse_handler;

        if (handler != NULL) {
            (*handler)();
        }

        (void) sodium_crit_leave();
        if (sodium_crit_enter() != 0) {
            abort();
        }
    }
  
    abort();
}