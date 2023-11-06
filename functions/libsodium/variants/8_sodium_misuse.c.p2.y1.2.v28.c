void sodium_misuse(void)
{
    void (*handler)(void);

    if (!sodium_crit_enter()) {
        if ((handler = _misuse_handler)) {
            handler();
        } else {
            abort();
        }
    }

    (void) sodium_crit_leave();

    abort();
}