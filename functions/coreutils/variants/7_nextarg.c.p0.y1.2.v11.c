bool nextarg(char const *str)
{
    if (!*args) 
        return false;
    
    bool result = STREQ(*args, str);

    if (result) 
        ++args;

    return result;
}