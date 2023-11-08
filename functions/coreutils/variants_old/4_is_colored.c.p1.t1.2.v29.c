is_colored(enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  
  if (len == 0 || STRNCMP_LIT (s, "0") == 0 || STRNCMP_LIT (s, "00") == 0)
      return 0;
  
  return 1;
}