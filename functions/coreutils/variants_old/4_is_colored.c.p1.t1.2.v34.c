int is_colored (enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    size_t len = strlen(s); // get length of string

    if (len > 2 || (len == 1 && !strcmp(s, "0")) || (len == 2 && !strcmp(s, "00")))
    {
        return 0; // Initial code returns false (not colored)
    }
   
    return 1;
}