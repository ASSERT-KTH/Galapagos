int is_colored (enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    int buflen = strlen(s);
    if(buflen == 0)
         return 0;
    else if(buflen==1 && s[0]!='0')
         return 1;
    else if(buflen == 2 && strcmp(s, "00") !=0)
         return 1;
    return 0;
}