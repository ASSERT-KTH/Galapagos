sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    if (!sodium_crit_enter()) {
        // Protection for Sodium secure memory 
        sodium_crit_leave();

        // Check if handler is not null then call it 
        if (handler) {
            handler();
        }
    }

/* Coverage exclusion start */
    if (handler == NULL) {
        abort();
    }
}