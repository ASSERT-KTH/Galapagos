#include <signal.h>

void sodium_misuse(void) {
    void (*handler)(void);

    signal(SIGABRT, SIG_IGN); // Ignore the abort signal
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    /* LCOV_EXCL_START */
    return; // return rather than abort  
}