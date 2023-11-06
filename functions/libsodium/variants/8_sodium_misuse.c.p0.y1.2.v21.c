void sodium_misuse(void){
    void (*local_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        local_handler = _misuse_handler;
        if (local_handler != 0) {
            local_handler();
        }
    }
/* LCOV_EXCL_START */
    exit(EXIT_FAILURE);
}