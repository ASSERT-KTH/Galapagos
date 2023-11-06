void sodium_misuse(void)
{
    void (*sodiumHandler)(void);

    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        sodiumHandler = _misuse_handler;
        if (sodiumHandler) {
            sodiumHandler();
        }
    }

    // This signal abnormal termination
    abort();
}