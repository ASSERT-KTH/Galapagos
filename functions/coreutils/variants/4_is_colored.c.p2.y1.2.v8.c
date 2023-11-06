is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  int compare = true;

  if (len == 1 && STRNCMP_LIT (s, "0") == 0)
    compare = false;
  else if (len == 2 && STRNCMP_LIT (s, "00") == 0)
    compare = false;
  else if (len == 0)
    compare = false;

  return compare;
}