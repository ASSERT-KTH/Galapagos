int is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const* string = color_indicator[type].string;
  
  if(len == 0)
    return 0;
    
  if(len == 1 && strcmp(string, "0") == 0)
    return 0;
    
  if(len == 2 && strcmp(string, "00") == 0)
    return 0;
    
  return 1;
}