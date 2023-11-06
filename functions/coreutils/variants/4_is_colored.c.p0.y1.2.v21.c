is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if(len == 0 || (len == 1 && strstr(s, "0"))
     || (len == 2 && strstr(s, "00"))) 
     {
       return 0;
     }
    
  return 1;
}