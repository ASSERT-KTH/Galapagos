is_colored (enum indicator_no type)
{
  struct color_indicator ci = color_indicator[type];
  size_t len = ci.len; 
  char const *s = ci.string;

  if (len == 0)
    return 0;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0)
    return 0;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0)
    return 0;
  
  return 1; 
}