void sodium_misuse(void)
{
    void (*h)(void);
   
    (void)sodium_crit_leave();
    if (!sodium_crit_enter()) 
    {
        h=_misuse_handler;
        if(h)
        {
            (*h)();
        }
    }
   abort(); 
}