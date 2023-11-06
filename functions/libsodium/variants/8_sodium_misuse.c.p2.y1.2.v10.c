sodium_misuse(void)
{
    void (*handler)(void);
    int tmp_exit_status;

    tmp_exit_status = sodium_crit_leave();
    (void) tmp_exit_status;
   
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
        else {
            abort();
        }
    }
    else {
        abort();
    }
}