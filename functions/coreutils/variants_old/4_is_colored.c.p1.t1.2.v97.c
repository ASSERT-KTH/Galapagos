is_colored (enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    size_t len = 0;

    while(s[len] != '\0')
    {
        len++;
    }

    int is_zero = ((len == 1 && s[0] == '0') || (len == 2 && s[0] == '0' && s[1] == '0')) ? 1 : 0;

    return is_zero ? 0 : 1;
}