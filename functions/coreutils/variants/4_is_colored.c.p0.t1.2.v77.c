is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  bool is_len_zero  = len == 0;
  bool is_len_one_and_zero = len == 1 && STRNCMP_LIT (s, "0") == 0;
  bool is_len_two_and_double_zero = len == 2 && STRNCMP_LIT (s, "00") == 0;

  return !(is_len_zero || is_len_one_and_zero || is_len_two_and_double_zero);
}