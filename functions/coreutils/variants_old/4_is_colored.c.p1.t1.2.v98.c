is_colored (enum indicator_no type)
{
  color_indicator_t indicator = color_indicator[type];
  size_t len = indicator.len;
  char const *s = indicator.string;
  if (len == 0) 
  {
    return 0;
  }
  else if (len == 1 && STRNCMP_LIT (s, "0") == 0)
  {
    return 0;
  }
  else if (len == 2 && STRNCMP_LIT (s, "00") == 0)
  {
    return 0;
  }
  return 1;
}