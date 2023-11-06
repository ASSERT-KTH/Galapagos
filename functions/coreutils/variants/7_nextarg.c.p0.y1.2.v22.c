bool nextarg (char const *str)
{
    if (!*args)
        return false;

    bool r = STREQ (*args, str);
    if (r)
        args++;
    return r;
}