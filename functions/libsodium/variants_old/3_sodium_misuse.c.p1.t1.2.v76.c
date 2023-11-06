The following is a redesign of the original function with similar functionality:

void sodium_misuse(void)
{
    void (*handler)(void);

    int enteringCritSectVal = sodium_crit_enter(); 
    (void) sodium_crit_leave();
    
    if (!enteringCritSectVal) {  // If the return value of sodium_crit_enter() is 0
        handler = _misuse_handler;
        if (handler != NULL) {  // If _misuse_handler is defined, call the function it holds
            (*handler)();  
        }      
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }    
/* LCOV_EXCL_END */
}