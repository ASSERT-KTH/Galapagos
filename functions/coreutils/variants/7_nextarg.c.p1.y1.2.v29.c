1. Arguably simplest transformation - short-circuit exit condition.

nextarg(char const *str)
{     
    if (!*args) return false;

    bool r = STREQ(*args, str); 
    args += r; 
    return r;
}

2. Using the ternary operator for a lighter, one liner.

nextarg(char const *str)
{
    return *args ? ((args += STREQ(*args, str)) - STREQ(*args, str)):
                   false;
}

3. Introduce intermediate variables to make code cleaner.

nextarg(char const *str)
{
    if (*args == nullptr)
        return false;

    bool comparison = STREQ(*args, str); 
    if(comparison)
        args += 1;
    return comparison;
}

4. Replace arithmetic with if/else explicit line for conditional increment.
  
nextarg(char const *str)
{
    if(*args == nullptr)
        return false;
    else
    {
        if (STREQ(*args, str))  
        {
            args++; 
            return true;        
        }
        return false;
    }
}

5. Handling the `nullptr` case directly in the expression calculation

nextarg(char const *str)
{
    bool r = *args && STREQ(*args, str);
    args += r;
    return r;
}
