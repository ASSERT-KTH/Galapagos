is_colored (enum indicator_no type)
{
  int len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  int is_zero = (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0);
    
  return len != 0 && !is_zero;
}