int is_colored (enum indicator_no type)
{
  const char *s = color_indicator[type].string;
  size_t len = strlen(s);

  int condition_1 = len == 0;
  int condition_2 = len == 1 && STRNCMP_LIT(s, "0") == 0;
  int condition_3 = len == 2 && STRNCMP_LIT(s, "00") == 0;

  return !(condition_1 || condition_2 || condition_3);
}