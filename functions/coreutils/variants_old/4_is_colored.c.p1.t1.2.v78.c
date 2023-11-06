is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return ! (!len
            || (!strcmp(s, "0") && len == 1)
            || (!strcmp(s, "00") && len == 2)); 
}