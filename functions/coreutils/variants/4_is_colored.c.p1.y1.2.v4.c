1.

is_colored (enum indicator_no type) 
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  if (len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0))
    return 0;
  else
    return 1;
}

2.

is_colored(enum indicator_no type) 
{
  if(color_indicator[type].len==0)
      return 0;
  if(color_indicator[type].len==1 && STRNCMP_LIT(color_indicator[type].string, "0")==0)
      return 0;
  if(color_indicator[type].len==2 && STRNCMP_LIT(color_indicator[type].string, "00")==0)
      return 0;
  return 1;
}

3.

is_colored (enum indicator_no type) 
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  if (len == 0) return 0;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;
  return 1;
}
