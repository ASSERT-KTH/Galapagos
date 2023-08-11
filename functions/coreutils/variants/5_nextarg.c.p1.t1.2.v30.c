char nextarg(const char *str)
{
    if (*args == '\0')
        return '0';
    else
    {
        char r = STREQ(*args, str) ? '1' : '0';
        args += r - '0';
        return r;
    }
}