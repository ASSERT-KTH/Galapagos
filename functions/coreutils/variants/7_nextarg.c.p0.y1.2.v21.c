int nextarg (const char *str)
{
    if (*args == '\0')
        return 0;
 
    int returnValue = STREQ (*args, str) ? 1 : 0;
    args += returnValue;
 
    return returnValue;
}