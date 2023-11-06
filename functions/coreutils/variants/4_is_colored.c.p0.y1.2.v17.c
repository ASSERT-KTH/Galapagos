bool is_colored(enum indicator_no type)
{
    bool ret_val;
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;

    if (len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0))
    {
        ret_val = false;
    } 
    else
    {
        ret_val = true;
    }

    return ret_val;
}