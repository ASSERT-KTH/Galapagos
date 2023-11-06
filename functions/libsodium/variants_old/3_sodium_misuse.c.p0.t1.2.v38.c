sodium_misuse(void)
{
    void (*func_handler)(void);

    (void) sodium_crit_leave();
    bool is_correct_entry = (sodium_crit_enter() == 0);
    if (is_correct_entry) {
        func_handler = _misuse_handler;
        if (func_handler) {
            (*func_handler)();
        }
    }

    if (!is_correct_entry)
        abort();    //The abort system call generates the SIGABRT signal to the current process
}
