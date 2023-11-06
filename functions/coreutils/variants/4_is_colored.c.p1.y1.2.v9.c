// Variant 1
is_colored (enum indicator_no type)
{
  // Destructure the color indicator
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  // Maintain base exit case
  if(len == 0) {
    return 0;
  }
  
  // Normalize lone and paired zero scenarios
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) {
    return 0;
  }
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) {
    return 0;
  }

  // Returns 1 if every if condition is false
  return 1;
}

// Variant 2
is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  
  if(len > 0 && strcmp(s, "0") != 0 && strcmp(s, "00") != 0) {
    return 1;
  }
  return 0;  
}

// Variant 3
is_colored (enum indicator_no type)
{
  const char *s = color_indicator[type].string;
  int len = strlen(s);

  return !(len == 0 || strcmp(s, "0") == 0 || strcmp(s, "00") == 0);
}