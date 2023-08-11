sodium_misuse(void)
{
    void (*curr_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        curr_handler = _misuse_handler;
        if (curr_handler != NULL) {
            curr_handler();
        } else {
            return;
        }
    } 

    abort();
}