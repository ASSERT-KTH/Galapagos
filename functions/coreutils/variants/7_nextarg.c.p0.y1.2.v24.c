int nextarg (const char *str)
{
    if (*args == NULL)
        return 0;
    int compareVal = strcmp(*args, str);
    if (compareVal == 0)
    {
        args++;
        return 1;
    }
    return 0;
}