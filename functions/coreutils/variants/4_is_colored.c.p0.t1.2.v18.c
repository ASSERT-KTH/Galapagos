is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *code = color_indicator[type].string;
  bool is_empty = len == 0;
  bool is_zero = (len == 1 && STRNCMP_LIT (code, "0") == 0);
  bool is_double_zero = (len == 2 && STRNCMP_LIT (code, "00") == 0);
  
  return !(is_empty || is_zero || is_double_zero);
}