bool is_colored(enum indicator_no type) 
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  if(!len)
    return false;
  else if(len == 1 && strcmp(s, "0") == 0)
    return false;
  else if(len == 2 &&(strcmp(s, "00") == 0)
    return false;
    
  return true;
}