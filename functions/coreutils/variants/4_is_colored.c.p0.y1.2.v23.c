is_colored (enum indicator_no type)
{
  size_t indicator_length = color_indicator[type].len;
  char const *indicator_str = color_indicator[type].string;
  if (indicator_length == 0) return 0;
  
  if (indicator_length == 1 && STRNCMP_LIT (indicator_str, "0") == 0) return 0;

  if (indicator_length == 2 && STRNCMP_LIT (indicator_str, "00") == 0) return 0;

  return 1;
}