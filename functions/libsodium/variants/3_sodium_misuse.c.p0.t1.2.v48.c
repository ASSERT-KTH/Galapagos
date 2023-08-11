sodium_misuse(void)
{
    void (*funcHndl)(void);

    int isCritEntered = sodium_crit_enter();

    (void) isCritEntered;
    (void) sodium_crit_leave();

    if (!isCritEntered) {
        funcHndl = _misuse_handler;
        if (funcHndl != NULL) {
            funcHndl();
        }
    }
/* LCOV_EXCL_START */
    if(isCritEntered != 0) {
        abort();
    }
}