is_colored_2(enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  const char *str = color_indicator[type].string;
  if(length == 0){
    return 0;
  }
  else if(length == 1) {
    if(STRNCMP_LIT (str, "0") == 0) 
      return 0;
  }
  else if(length == 2) {
    if(STRNCMP_LIT (str, "00") == 0)
      return 0;
  }
  return 1;
}