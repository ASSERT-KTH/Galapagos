void sodium_misuse(void)
{
    void (*handler)(void);
    (void) sodium_crit_leave();
	    
    int check = sodium_crit_enter();
	    
    if (!check) {
        if(_misuse_handler != NULL)
	        _misuse_handler();
    }
    abort();
}