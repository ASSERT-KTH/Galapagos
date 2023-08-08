void sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    (void) sodium_crit_leave(); 
    if (sodium_crit_enter() == 0) {
        if (handler == NULL) {
            handler = _misuse_handler;
        }
        if (handler != NULL) {
            handler();
        } 
    } else {
        // Behaviour change: the function bypass without calling the handler if enter the critical section.
        return;
    }

    abort();

}