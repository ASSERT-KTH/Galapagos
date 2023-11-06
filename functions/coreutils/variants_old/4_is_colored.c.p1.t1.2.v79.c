int is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  
  if (len == 0) 
    return 0;
  
  if ((len == 1 && strncmp(s, "0", 1) == 0) || (len == 2 && strncmp(s, "00", 2) == 0))
    return 0;
  
  return 1;
}