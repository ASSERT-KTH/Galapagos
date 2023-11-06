is_colored (enum indicator_no type)
{
  indicator_t indicator = color_indicator[type];
  size_t len = indicator.len;
  char const *s = indicator.string;

  if (len == 0) 
  {
    return 0;
  }   
  else if ((len == 1 && STRNCMP_LIT (s, "0") == 0)
            || (len == 2 && STRNCMP_LIT (s, "00") == 0))
  {
    return 0;
  } 
  else
  {
    return 1;
  }
}