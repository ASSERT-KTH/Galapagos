is_colored (enum indicator_no type)
{
  Color c = color_indicator[type];
  size_t len = c.len;
  char const *s = c.string;
  
  return !(len == 0
    || (len == 1 && s[0] == '0')
    || (len == 2 && s[0] == '0' && s[1] == '0'));
}