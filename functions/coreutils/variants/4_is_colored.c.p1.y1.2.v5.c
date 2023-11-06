/** 
 * Variant 1 
 * Same as the previous code, just reordered the logic 
 */ 
is_colored (enum indicator_no type) {
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return !(len == 2 && STRNCMP_LIT (s, "00") == 0)
         && !(len == 1 && STRNCMP_LIT (s, "0") == 0)
         && !(len == 0);
}

/** 
 * Variant 2 
 * Extracted condition to separate lines for readability
 */ 
is_colored (enum indicator_no type) {
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0) return 0;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;
  
  return 1;
}

/** 
 * Variant 3 
 * Conditional checks combined to a binary OR for succinctness 
 */ 
is_colored (enum indicator_no type) {
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  return !((len == 0) | (len == 1 &&  !(STRNCMP_LIT (s, "0"))) | (len == 2 && STRNCMP_LIT (s, "00") == 0));
}

/** 
 * Variant 4 
 * Use of descriptive variable to make code self documenting
 */ 
is_colored (enum indicator_no type) {
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  bool isDefaultColor = (len == 0) 
                        || (len == 1 && STRNCMP_LIT (s, "0") == 0)
                        || (len == 2 && STRNCMP_LIT (s, "00") == 0);
                        
  return !isDefaultColor;
}