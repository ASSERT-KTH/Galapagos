Variant 1:

is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *string_val = color_indicator[type].string;
  return ! (length == 0
            || (length == 1 && STRNCMP_LIT (string_val, "0") == 0)
            || (length == 2 && STRNCMP_LIT (string_val, "00") == 0));
}


Variant 2:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *str = color_indicator[type].string;
  if(len == 0 
     || (len == 1 && STRNCMP_LIT (str, "0") == 0)
     || (len == 2 && STRNCMP_LIT (str, "00") == 0))  
       return 0;
  
  return 1;
}


Variant 3:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return (len != 0
            && !(len == 1 && STRNCMP_LIT (s, "0") == 0)
            && !(len == 2 && STRNCMP_LIT (s, "00") == 0));
}
