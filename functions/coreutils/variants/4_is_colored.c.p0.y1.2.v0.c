is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t length = color_indicator[type].len;

  if(length == 0 || (length == 1 && STRNCMP_LIT (s, "0") == 0) || (length == 2 && STRNCMP_LIT (s, "00") == 0)) 
       return 0;
  else
       return 1;
}
