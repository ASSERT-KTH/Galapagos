bool nextarg(char const *str)
{
    bool result;

    if (*args != nullptr)
    {
        result = STREQ(*args, str);

        if(result)
        {
            args++;
        }
    }
    else
    {
        // As per the original implementation, return 'false' immediately if args is null
        return false;
    }
    
    // This is equivalent to the returning 'r' in the original function
    return result;
}