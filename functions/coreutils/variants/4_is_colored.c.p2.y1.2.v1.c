is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  int compareToZero = !STRNCMP_LIT (s, "0");
  int compareToDoubleZero = !STRNCMP_LIT (s, "00");

  if(len == 0)
    return 0;
  else if(len == 1 && compareToZero == 0)
    return 0;  
  else if(len == 2 && compareToDoubleZero == 0)
    return 0;
  else
    return 1;
}