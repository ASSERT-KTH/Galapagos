bool is_colored(enum indicator_no type) 
{
  size_t indicator_len = color_indicator[type].len;
  char const *str = color_indicator[type].string;

  if(indicator_len == 0)
    return false;

  if(indicator_len == 1) 
  {
    if(STRNCMP_LIT (str, "0") == 0)
      return false;
  } 

  if(indicator_len == 2)
  {
    if(STRNCMP_LIT (str, "00") == 0)
      return false;
  }

  return true;
}