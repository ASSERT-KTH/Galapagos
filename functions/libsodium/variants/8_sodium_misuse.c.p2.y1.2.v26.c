void sodium_misuse(void)
{
    // Declare handler of type pointer to function which accepts no argument and has no return type
    void (*handler)(void);
    // Exiting the sodium critical section
    sodium_crit_leave(); 
    // Enter in the Sodium Critical region, if enters successfully, check for the _misuse_handler
    if (!sodium_crit_enter()) {
        handler = _misuse_handler;    
        // this check the function whaether it is assignable or not
        if (handler) {
            (*handler)();  // if it does. calls handler() function
        }
    }
    // No execution beyond this point as it calls abort function
    abort();  
}