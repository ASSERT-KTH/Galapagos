is_colored (enum indicator_no type)
{
  size_t str_length = color_indicator[type].len;
  char const *str_value = color_indicator[type].string;

  if (str_length == 0)
    return 0;
  else if (str_length == 1)
  {
    if (STRNCMP_LIT (str_value, "0") == 0)
      return 0;
  }
  else if (str_length == 2)
  {
    if (STRNCMP_LIT (str_value, "00") == 0)
      return 0;
  }
  return 1;
}