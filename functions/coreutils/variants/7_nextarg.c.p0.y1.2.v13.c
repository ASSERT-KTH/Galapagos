nextarg(char const *str)
{
    if (!*args)
        return false;
    else
    {
        bool isEqual = !strcmp(*args, str);
        args += isEqual;
        return isEqual;
    }
}