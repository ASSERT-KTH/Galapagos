int is_colored (enum indicator_no type) 
{
    size_t length = color_indicator[type].len;
    char const *str = color_indicator[type].string;

    if(length == 0) return 0;

    if(length == 1 && str[0] == '0') return 0;

    if(length == 2 && str[0] == '0' && str[1] == '0') return 0;

    return 1;
}