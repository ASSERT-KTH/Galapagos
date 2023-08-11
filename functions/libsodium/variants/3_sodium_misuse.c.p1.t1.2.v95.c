sodium_misuse(void)
{
    void (*handler)(void);
    status_t sodium_critical_stage_status;

    sodium_critical_stage_status = sodium_crit_enter();
    sodium_crit_leave();

    if (sodium_critical_stage_status == 0) {
        handler = _misuse_handler;
        if (handler !=  NULL) {
            handler();
        }
    } else {
    /* In case some parallel process or incorrect function behavior attempts to enter
    critical stage after sodium_crit_leave, there's space for handling such invalid 
    situation: error logging, damage control, etc. Leaving the error status handling 
    as variables in function body pushes the concrete error handling decisions out 
    to the calling API level or sometimes even beyond, to MISRA OS level. */

    /* LCOV_EXCL_START */
    abort(); 
    }
}