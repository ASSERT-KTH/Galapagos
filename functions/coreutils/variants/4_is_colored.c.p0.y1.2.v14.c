int is_colored (enum indicator_no type)
{
  size_t str_length = color_indicator[type].len;
  char const *str = color_indicator[type].string;

  if (str_length == 0) {
    return 0;
  }
    
  if (str_length == 1 && strcmp(str,"0") == 0) {
    return 0;
  }

  if (str_length == 2 && strcmp(str,"00") == 0) {
    return 0;
  } 

  return 1; 
}