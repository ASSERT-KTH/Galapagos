1) Iterative form

bool nextarg (char const **args, char const *str) 
{
    while (*args) 
    {
        if (STREQ (*args, str)) 
        {
            *args++;
            return true;
        }
        *args++;
    }
    return false;
}

2) Using conditional operator form

bool nextarg (char const **args, char const *str) 
{
    return *args ? (bool)(args += STREQ (*args, str)), STREQ (*args, str) : false;
}

3) Avoid conditional operator

bool nextarg (char const **args, char const *str) 
{
    if (*args) 
    {
        bool result = STREQ (*args, str);
        if(result) {*args++;}
        return result;
    }
    else 
    {
        return false;
    }
}
  
4) Consolidate conditional operator

bool nextarg (char const **args, char const *str)
{
    bool result = (*args != nullptr) && STREQ (*args, str);
    if (result)
    {
        (*args)++;
    }
    return result;
}

5) Mix of above code transformations

bool nextarg (char const **args, char const *str) 
{
    if (*args) 
    { 
        return (bool)(*args += STREQ (*args, str)), STREQ(*args--,str);
    } 
    
    return false;
}