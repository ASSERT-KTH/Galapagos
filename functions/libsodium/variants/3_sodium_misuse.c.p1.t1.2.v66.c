sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();

    /* On successful entry, invoke the handler, then, regardless of if it worked or not, exit the critical section and abort. */
    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
        (void) sodium_crit_leave();
    }
    /* If it didn't enter, also abort, the critical section doesn't need to be exited. */
    abort();
}