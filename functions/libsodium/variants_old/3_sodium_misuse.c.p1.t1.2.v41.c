Here the behavior is slightly altered to print debug info during development or for testing purposes. It will help to identify what's causing the misuse if `_misuse_handler` function is not already set.


#include <stdio.h>

void sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        } else {
            // If `_misuse_handler` is not set, print debug info.
            printf("Error: _misuse_handler is not set.\n");
        }
    }
    /* LCOV_EXCL_START */
    abort();
}


Please note that writing to stdout could create other side effects elsewhere depending on how the environment and usage of this function. So use such a change with caution.