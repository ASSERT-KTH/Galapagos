is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *string = color_indicator[type].string;
  return ! (length == 0
            || (length == 1 && STRNCMP_LIT (string, "0") == 0)
            || (length == 2 && STRNCMP_LIT (string, "00") == 0));
}