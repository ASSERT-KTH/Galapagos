Variant 1:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0
      || (len == 1 && STRNCMP_LIT (s, "0") == 0)
      || (len == 2 && STRNCMP_LIT (s, "00") == 0))
  {
    return 0;
  }
  return 1;
}


Variant 2:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  size_t isZero = (len == 1 && STRNCMP_LIT (s, "0") == 0) ? 1 : 0;
  size_t isDoubleZero = (len == 2 && STRNCMP_LIT (s, "00") == 0) ? 1 : 0;
  return ! (len == 0 || isZero || isDoubleZero);
}


Variant 3:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return (len != 0 && ((len != 1 || STRNCMP_LIT (s, "0") != 0) && (len != 2 || STRNCMP_LIT (s, "00") != 0))) ? 1 : 0;
}

  
Variant 4:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if(len != 0 && len != 1 && len != 2)
    return 1;

  if(len == 1) 
    return !(STRNCMP_LIT (s, "0") == 0);

  if(len == 2) 
    return !(STRNCMP_LIT (s, "00") == 0);

  return 0;
}
