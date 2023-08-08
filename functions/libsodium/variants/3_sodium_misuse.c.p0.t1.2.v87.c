sodium_misuse(void)
{
    void (*alt_handler)(void);
    alt_handler = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (alt_handler != NULL) {
            alt_handler();
        }
        else{
            abort();
        }
    }
    else{
        abort();
    }
}