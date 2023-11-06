int is_colored(enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    size_t len = color_indicator[type].len;

    if (len == 0)
    {
        return 0;
    }
    else if ((len == 1 && strcmp(s, "0") == 0) || (len == 2 && strcmp(s, "00") == 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}