is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0) return false;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) return false;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) return false;
  
  return true;    
}