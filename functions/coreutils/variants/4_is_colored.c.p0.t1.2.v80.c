is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  return !(len == 0 
           || (len == 1 && *s == '0' && s[1] == '\0')
           || (len == 2 && *s == '0' && *(s+1) == '0' && *(s+2) == '\0'));
}