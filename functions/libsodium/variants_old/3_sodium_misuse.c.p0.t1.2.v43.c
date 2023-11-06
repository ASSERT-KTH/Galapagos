sodium_misuse(void)
{
    void (*secHandler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 1) {
        secHandler = _misuse_handler;
        if (secHandler != NULL) {
            secHandler();
        }
        else {
            abort();
        }
    }
    abort();
}