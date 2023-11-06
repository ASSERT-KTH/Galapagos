is_colored (enum indicator_no type)
{
   char const *s = color_indicator[type].string;
   return ! (s[0] == '\0' 
              || (s[0] == '0' && s[1] == '\0')
              || (s[0] == '0' && s[1] == '0' && s[2] == '\0'));
}