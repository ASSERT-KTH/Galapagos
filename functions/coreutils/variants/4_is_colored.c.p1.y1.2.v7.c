Version 1:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return len != 0 && len != 1
         && len != 2
         && STRNCMP_LIT (s, "0") != 0
         && STRNCMP_LIT (s, "00") != 0;
}


Version 2:

is_colored (enum indicator_no type)
{
  return color_indicator[type].len > 0
         && !(color_indicator[type].len == 1 && STRNCMP_LIT (color_indicator[type].string, "0") == 0)
         && !(color_indicator[type].len == 2 && STRNCMP_LIT (color_indicator[type].string, "00") == 0);
}


Version 3:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if (len == 0) 
    return 0;
  
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) 
    return 0;
  
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) 
    return 0;

  return 1;
}


Version 4:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0))
    return 0;

  return 1;
}
