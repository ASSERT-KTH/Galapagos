char* nextarg (char const *str, char **args)
{
    if (!*args) 
    {
        return NULL; 
    }
    else
    {
        int result = strcmp(*args, str) == 0;
        *args += result;
        return result? *args : NULL;
    }
}