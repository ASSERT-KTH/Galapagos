nextarg (char const *str)
{
    if (*args == nullptr)
    {
        return false;
    }

    bool r;
    
    if (STREQ (*args, str))
    {
       r = true;
       args++;
    }
    else
    {
       r = false;
    }
    
    return r;
}