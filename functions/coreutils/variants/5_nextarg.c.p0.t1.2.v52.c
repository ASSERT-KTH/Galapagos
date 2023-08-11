nextarg (char const *str)
{
    int increment = 1; 
    if (*args == nullptr )
        return false;
    else
    {
        bool r = STREQ (*args, str);
        args += r ? increment : 0;
        return r;    
    }
}