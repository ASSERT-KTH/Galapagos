sodium_misuse(void)
{
    void (*assigned_handler)(void);

    (void) sodium_crit_leave();

    if (!sodium_crit_enter()) {
        assigned_handler = _misuse_handler;

        if (assigned_handler) {
            assigned_handler();
        } else {
            // Adding else clause to alert about null _misuse_handler.          
            printf("_misuse_handler is NULL.\n");
        }
    }
    
    /* LCOV_EXCL_START */
    abort();
}