bool is_colored(enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    
    if(strcmp(s, "0") == 0 || strcmp(s, "00") == 0)
        return false;
    else
        return true;
}