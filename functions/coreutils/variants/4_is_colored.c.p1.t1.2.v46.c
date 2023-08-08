is_colored(enum indicator_no type)
{
  struct color_indicator_color{char* string; size_t len; } color;
  color = color_indicator[type];
  
  if(color.len == 0) 
    return 0;
  
  if(color.len == 1 && strncmp(color.string, "0", 1) == 0) 
    return 0;
  
  if(color.len == 2 && strncmp(color.string, "00", 2) == 0) 
    return 0;
  
  return 1;
}