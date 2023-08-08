sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
    }
    else {
        abort();
    }

    if (handler != NULL) {
        (*handler)();
    }
    else{
        abort();
    }
}