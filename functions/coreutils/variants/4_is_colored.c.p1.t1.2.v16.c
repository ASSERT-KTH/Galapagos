is_colored(enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    if(s == NULL)
    {
        return 0;
    }
    size_t len = strlen(s);
    if(len == 0)
    {
        return 0;
    }
    if((len == 1 && strcmp(s, "0") == 0) || (len == 2 && strcmp(s, "00") == 0))
    {
        return 0;
    }
    return 1;
}