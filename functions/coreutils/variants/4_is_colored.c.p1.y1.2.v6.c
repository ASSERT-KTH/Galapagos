
is_colored(enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
 
  if (len == 0)
  {  
    return 0; 
  }
  else if (len == 1)
  {  
    return !(STRNCMP_LIT (s, "0") == 0); 
  }
  else if(len == 2)
  {
    return !(STRNCMP_LIT (s, "00") == 0); 
  }
  else
  {  
    return 1; 
  }
} 



is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  int colored = 1;

  if(len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0))
  {
    colored = 0;
  }

  return colored;
}



is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  return len != 0 && (!(len == 1 && STRNCMP_LIT (s, "0") == 0)) && (!(len == 2 && STRNCMP_LIT (s, "00") == 0));
}
