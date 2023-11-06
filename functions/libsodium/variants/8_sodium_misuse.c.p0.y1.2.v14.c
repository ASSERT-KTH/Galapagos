void sodium_misuse(void)
{
    void (*function_ptr)(void);

    sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        function_ptr = _misuse_handler;
        if (function_ptr) {
            function_ptr();
        }
    }

    exit(1);
}