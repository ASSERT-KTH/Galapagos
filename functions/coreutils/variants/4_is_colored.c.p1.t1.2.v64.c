is_colored(enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    const char *s = color_indicator[type].string;

    if(len == 0) return 0; 
    
    if(len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
    
    if(len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;

    return 1;
}