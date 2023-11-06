
void sodium_misuse(void) {
    void (*handler)(void);

    (void) sodium_crit_leave();
    int err = sodium_crit_enter();
    if (err == 0) {
        /* if there was no error (sodium_crit_enter returned 0), 
           set the handler to handle misuse */
        handler = _misuse_handler;
        if (handler != NULL) {
            /* call the misuse handler function addressed by the pointer */
            handler();
        }
        else {
            /* if the handler function pointer is NULL, do not call the function */
            return;
        }
    }

    /* In the original code, the abort function is called unconditionally,
       which means the process is terminated with an abnormal program termination. 
       In this variant, we only call it when an error occurred during sodium_crit_enter 
       */
    if (err != 0) abort();
}
