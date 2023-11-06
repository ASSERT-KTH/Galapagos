#define STR_EQUAL 0

int nextarg (char const *str)
{
    if (*args == NULL)
    {
        return 0;
    }

    int strComparison = strcmp(*args, str);

    if (strComparison == STR_EQUAL)
    {
        args++;
        return 1;
    }
    
    return 0;
}