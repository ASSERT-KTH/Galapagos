int is_colored(enum indicator_no type) {
  char const* s = color_indicator[type].string;
  int is_zero_str = (strcmp(s, "0") == 0 || strcmp(s, "00") == 0);
  int is_empty_or_zero = (color_indicator[type].len == 0) || (color_indicator[type].len == 1 && is_zero_str) 
                         || (color_indicator[type].len == 2 && is_zero_str);
  return !is_empty_or_zero;
}