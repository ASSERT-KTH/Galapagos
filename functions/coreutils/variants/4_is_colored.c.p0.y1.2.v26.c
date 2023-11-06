int is_colored (enum indicator_no type)
{
  int result = 1;
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0 || (len == 1 && strncmp(s, "0", 1) == 0) || (len == 2 && strncmp(s, "00", 2) == 0)) {
      result = 0;
  }
  
  return result;
}