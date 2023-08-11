is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  int comparison1 = strcmp (s, "0");
  int comparison2 = strcmp (s, "00");

  return !((len == 0) || (len == 1 && comparison1 == 0) || (len == 2 && comparison2 == 0));
}