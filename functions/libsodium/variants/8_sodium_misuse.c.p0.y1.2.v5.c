void sodium_misuse(void)
{
    void (*misuse_handler_copy)(void);

    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        misuse_handler_copy = _misuse_handler;

        if (misuse_handler_copy) {
            (*misuse_handler_copy)();
        }
    }

    abort();
}