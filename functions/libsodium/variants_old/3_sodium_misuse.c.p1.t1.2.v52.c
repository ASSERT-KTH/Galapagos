You can change the implementation by adding an `exit()` statement, and printing an error message to stderr before aborting as follows:


#include <stdio.h>
#include <stdlib.h>

void sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    
    /* A message has been added to let you know when sodium usage has been misused */
    
    fputs("sodium usage has been misused, aborting...\n", stderr);
    
    /* If an error code -1 is desired when the function returns misuse,  
       You can use `exit(-1)` before `abort()` */
    
    exit(-1);
    /* LCOV_EXCL_START */
    abort();
}

Please note that the if `exit()` is called, `abort()` is never reached. The `exit()` function terminates the C program normally, whereas `abort()` brings an abnormal program termination, which is why in the given context `abort()` has been given preference.