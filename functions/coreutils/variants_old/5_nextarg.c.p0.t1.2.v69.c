nextarg(char const* str)
{
    if (*args == nullptr) 
    {
        return false;
    } 
    else 
    {
        int match = STREQ (*args, str);
    
        if (match == 1)
        {
            args += 1;
        }
        return match;
    }
}