void sodium_misuse(void)
{
    void (*handler)(void);
    int entry_result;

    (void) sodium_crit_leave();
    entry_result = sodium_crit_enter();

    if (entry_result == 0) {
        handler = _misuse_handler;
    }
    else {
        abort();
    }

    if (handler != NULL) {
        handler();
        abort();
    }
}