
is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  return !(len == 0
           || (len == 1 && s[0] == '0')
           || (len == 2 && s[0] == '0' && s[1] == '0'));
}
