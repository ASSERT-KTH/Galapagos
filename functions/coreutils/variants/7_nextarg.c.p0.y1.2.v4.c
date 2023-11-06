bool nextarg (char const *str)
{
    if (*args == NULL)
        return false;

    bool r = (*args == str);
    if (r)
        args++;
    return r;
}