int is_colored(enum indicator_no type) 
{
    char const *s = color_indicator[type].string;
    if (s[0] == '\0') 
    {
        return 0;
    }
    else if (s[0] == '0' && s[1] == '\0') 
    {
        return 0;
    }
    else if (s[0] == '0' && s[1] == '0' && s[2] == '\0') 
    {
        return 0;
    }
    return 1;
}