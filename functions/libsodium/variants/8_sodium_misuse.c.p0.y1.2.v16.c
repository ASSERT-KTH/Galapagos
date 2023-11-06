void sodium_misuse(void)
{
    if (!sodium_crit_enter()) 
    {
        if (_misuse_handler != NULL) 
        {
          (*_misuse_handler)();
        }
    }
    sodium_crit_leave();  
    abort();
}