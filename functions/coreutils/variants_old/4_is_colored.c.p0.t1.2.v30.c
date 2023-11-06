is_colored (enum indicator_no type)
{
  size_t len_count = color_indicator[type].len;
  char const *string = color_indicator[type].string;

  if(len_count == 0) return 0;
  if(len_count == 1 && STRNCMP_LIT (string, "0") == 0) return 0;
  if(len_count == 2 && STRNCMP_LIT (string, "00") == 0) return 0;
  
  return 1;
}