Function Variant 1:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0) return 0;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;
  
  return 1;
}


Function Variant 2:

is_colored (enum indicator_no type)
{
  color_indicator_t myColorIndicator = color_indicator[type];
  
  if (myColorIndicator.len == 0 || 
  (myColorIndicator.len == 1 && STRNCMP_LIT (myColorIndicator.string, "0") == 0) || 
  (myColorIndicator.len == 2 && STRNCMP_LIT (myColorIndicator.string, "00") == 0)){

    return 0;
  }
  
  return 1;  
}


Function Variant 3:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  int isNotColored = ((len == 1 && STRNCMP_LIT (s, "0") == 0) ||
                      (len == 2 && STRNCMP_LIT (s, "00") == 0));
  
  return !(len == 0 || isNotColored);
}
