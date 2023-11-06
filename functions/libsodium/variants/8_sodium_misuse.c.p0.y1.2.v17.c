void sodium_misuse(void) 
{
    sodium_crit_leave();
    if (sodium_crit_enter() == 0 && _misuse_handler != NULL) 
    {
        _misuse_handler();
    }

    abort();
}