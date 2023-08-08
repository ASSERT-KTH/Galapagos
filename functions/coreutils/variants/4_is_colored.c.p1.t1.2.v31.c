is_colored (enum indicator_no type)
{
  struct color_indicator *ci = &color_indicator[type];
  char const *s = ci->string;
  
  switch (ci->len)
  {
    case 0:
      return 0;
    case 1:
      return STRNCMP_LIT (s, "0") != 0;
    case 2:
      return STRNCMP_LIT (s, "00") != 0;
  }
  return 1;
}