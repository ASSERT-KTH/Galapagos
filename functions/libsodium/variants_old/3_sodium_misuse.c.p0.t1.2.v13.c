sodium_misuse(void)
{
    void (*procedure)(void);
    
    if(sodium_crit_enter()==0){
        (void) sodium_crit_leave();
        procedure=_misuse_handler;
        if(procedure){
            procedure();
        }
    }
    exit(0);
}