is_colored(enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  bool isZeroCode = !strcmp(s, "0") || !strcmp(s, "00");
  return !(!*s || (strlen(s) <= 2 && isZeroCode));
}