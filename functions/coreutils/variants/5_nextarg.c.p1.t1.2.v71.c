char *nextarg(char const *str)
{
    if (str == nullptr)
        return false;
    bool r = (strcmp(args, str) == 0);
    if (r)
        args++;
    return r;
}