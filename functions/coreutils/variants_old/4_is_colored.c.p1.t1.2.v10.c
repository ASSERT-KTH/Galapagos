is_colored (enum indicator_no type)
{
  ColorIndicator *current_indicator = &color_indicator[type];
  size_t len = current_indicator->len;
  char const *s = current_indicator->string;

  if(len == 0)
    return 0;
  
  if(len == 1 && STRNCMP_LIT (s, "0") == 0)
    return 0;
  
  if(len == 2 && STRNCMP_LIT (s, "00") == 0)
    return 0;
  
  return 1;
}