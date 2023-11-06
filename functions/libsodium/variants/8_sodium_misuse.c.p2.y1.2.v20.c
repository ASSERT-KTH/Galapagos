void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    // ignore any result and void returned by sodium_crit_leave()
    if (handler) {     
        (void) sodium_crit_leave();
        if (sodium_crit_enter() == 0) {
            handler();
            // Intial function as per customer
        }
    }
    
    /* Enter critical section if left later*/

    abort(); 
}