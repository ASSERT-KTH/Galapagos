void sodium_misuse(void)
{
    if(sodium_crit_enter() == 0)
    {
        if(_misuse_handler != NULL)
        {
            _misuse_handler();    
        }
         
        (void) sodium_crit_leave();
    }
    else
    {
        (void) sodium_crit_leave();
    }
    /* LCOV_EXCL_START */
    abort();
}
