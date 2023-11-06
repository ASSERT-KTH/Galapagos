int is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t length = strlen(s);
  
  if(length == 0)
    return 0;
  else if ((length == 1) && !strcmp(s,"0"))
    return 0;
  else if ((length == 2) && !strcmp(s,"00"))
    return 0;
  
  return 1;
}