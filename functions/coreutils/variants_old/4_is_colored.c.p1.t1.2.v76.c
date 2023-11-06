int is_colored (enum indicator_no type)
{
  // cache variables
  char const *s = color_indicator[type].string;
  size_t len = color_indicator[type].len;

  // check conditions in separate functions for clarity
  int is_zero = (len == 1 && strncmp(s, "0", 1) == 0) ? 1 : 0;
  int is_double_zero = (len == 2 && strncmp(s, "00", 2) == 0) ? 1 : 0;

  // reverse the result as originally done
  return !((len == 0) || is_zero || is_double_zero);
}