nextarg (char const *str)
{
    if (!*args)
        return (false);
        
    bool r;
    r = STREQ (*args, str);
    
    if (r == true)
        args++;
        
    return r;
}