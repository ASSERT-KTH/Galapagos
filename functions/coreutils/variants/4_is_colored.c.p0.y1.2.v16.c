is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if(len == 0 || (len == 1 && *s == '0') || (len == 2 && strcmp(s, "00") == 0))
    return 0;
  else
    return 1;
}