void sodium_misuse(void)
{
    static void (*handler)(void) = _misuse_handler;

    int lock_result = sodium_crit_enter();

    // Only after successfully enter the code area to avoid some potential race condition
    if (lock_result == 0) {
        if (handler != NULL) {
            handler();
        }
        (void) sodium_crit_leave();
    }

    // application specific abort strategy, we can fill in as per requirement
    abort();
}