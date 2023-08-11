is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  int is_zero = (len == 1 && STRNCMP_LIT (s, "0") == 0);
  int is_double_zero = (len == 2 && STRNCMP_LIT (s, "00") == 0);
  return !(len == 0 || is_zero || is_double_zero);
}