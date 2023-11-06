is_colored (enum indicator_no type)
{
  size_t length_color_indicator = color_indicator[type].len;
  char const *indicator_string = color_indicator[type].string;
  
  // Early exit if length_color_indicator is 0
  if(length_color_indicator == 0) return 0;
  // Early exit if length is 1 and single character match case
  if(length_color_indicator == 1 && STRNCMP_LIT (indicator_string, "0") == 0) return 0;
  // Check for double character match case
  if(length_color_indicator == 2 && STRNCMP_LIT (indicator_string, "00") == 0) return 0;
  
  return 1;
}