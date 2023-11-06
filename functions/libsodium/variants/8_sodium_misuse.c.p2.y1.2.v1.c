void sodium_misuse(void)
{
    void(*handler)(void);
    
    if(sodium_crit_enter() != 0) { 
        abort(); // Difference is placing abort here based upon condition set by sodium_crit_enter()
    }
    
    (void) sodium_crit_leave(); 

    handler = _misuse_handler;
    if (handler != NULL) {
        handler();
    }
    else {
        abort();
    }
}