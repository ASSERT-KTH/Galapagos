is_colored (enum indicator_no type)
{
    unsigned char const *s = color_indicator[type].string;
    if(s[0] != '\0') {
        if(s[0] == '0') {
            return (s[1] != '0' || s[1] == '\0') ? 1: 0;
        }
        return 1;
    }   
    return 0;
}