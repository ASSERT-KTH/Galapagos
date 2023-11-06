sodium_misuse(void)
{
    void (*error_handler)(void);

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        error_handler = _misuse_handler;
        if (error_handler) {
            error_handler();
        }
        sodium_crit_leave();
        if (!sodium_crit_enter()) {
            abort();
        }
    }
}