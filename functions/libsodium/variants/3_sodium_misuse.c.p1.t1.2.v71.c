
void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    } else {
        abort();
    }
}


Similar behavior to the earlier C function is kept in this variant. If we aren't able to enter the critical section or no handler is set, we immediately abort the program. But in the original version, no matter handler error or anything it just aborts the program. It does not validate if critical section enter is success or failure.