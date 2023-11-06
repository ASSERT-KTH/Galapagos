is_colored (enum indicator_no type)
{
  size_t str_len = color_indicator[type].len;
  char const *color_str = color_indicator[type].string;
  
  if(str_len == 0 || str_len == 1 && STRNCMP_LIT (color_str, "0") == 0 || str_len == 2 && STRNCMP_LIT (color_str, "00") == 0)
    return 0;
  else
    return 1;
}