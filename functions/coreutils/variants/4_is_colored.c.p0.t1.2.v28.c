is_colored (enum indicator_no type)
{
  char const *p = color_indicator[type].string;
  size_t length = color_indicator[type].len;

  if(length == 0)
  {
    return 0;
  }
  else if(length == 1 && STRNCMP_LIT (p, "0") == 0)
  {
    return 0;
  }
  else if(length == 2 && STRNCMP_LIT (p, "00") == 0)
  {
    return 0;
  }
  else
  {
    return 1;
  } 
}