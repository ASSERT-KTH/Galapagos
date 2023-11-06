
#include <stdio.h>
#include <stdlib.h>

void sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            printf("Program misuse detected.\n");
            handler();
        }
        return;
    }
    
    /* LCOV_EXCL_START */
    printf("Execution aborted.^.\n");
    abort();
}

This version of the function prints a message to stdout when possible program misuse is detected and before it's going to abort the program. Please note that two use of printf() would not change the fundamental functionality. Remarkably they just providing more transparency to what is going.