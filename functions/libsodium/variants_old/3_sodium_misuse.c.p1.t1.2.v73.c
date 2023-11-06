sodium_misuse(void)
{
    void (*handler)(void);
    // With push and pop functionality, sodium_crit_leave() will not completely leave the critical state.
    // Hence, we need to make sure this is properly followed by sodium_crit_enter() for managing concurrent issues. 
    (void) sodium_crit_leave();
    (void) sodium_crit_enter(); 
    handler = _misuse_handler;
    
    // Checking handler for null part excludes prevention uncertainty of failed pointer assign.
    if (handler != NULL) 
    {        
        handler();
        
        // Include abort() inside if clause to save process resources in watching handle execution  
        abort();
        (void) sodium_crit_leave();
    }
    else // No else block can create issues. It's safer to always check the worst case.
    {
        (void) sodium_crit_leave();
 
    }
}