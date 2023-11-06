int is_colored (enum indicator_no type)
{
  int len = (int) color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if (len == 0)
    return 0;
    
  if (len == 1 && strncmp(s, "0", len) == 0)
    return 0;
    
  if (len == 2 && strncmp(s, "00", len) == 0)
    return 0;
    
  return 1;
}