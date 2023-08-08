is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *st = color_indicator[type].string;
  if(length == 0) 
    return false;
 
  if(length == 1 && STRNCMP_LIT (st, "0") == 0) 
    return false;

  if(length == 2 && STRNCMP_LIT (st, "00") == 0)
    return false;

  return true;
}