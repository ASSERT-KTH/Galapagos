nextarg(char const *str)
{
    if (args[0] == '\0')
    {
        return false;
    }
    else
    {
        bool res = (strcmp(args, str) == 0 ? true : false);
        args += res;
        return res;
    }
}