nextarg(const char* str)
{
    if (*args == '\0')
    return false;
    else
    {
        bool result = (strcmp(*args, str) == 0);
        args += result;
        return result;
    }
}