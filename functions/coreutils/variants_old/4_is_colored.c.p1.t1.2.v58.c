An logical equivalent code may imply changing the organization of the conditions in the function. Below is the code adapted from the original implementation.


is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if(len == 0){
    return 0;
  }
  else if(len == 1 && STRNCMP_LIT (s, "0") == 0) {
    return 0;
  }
  else if(len == 2 && STRNCMP_LIT (s, "00") == 0) {
    return 0;
  } else {
    return 1;
  }
}


This refactored code attempts to initially return 0 (discolored) whenever it encounters the previous return conditions (not colored scenarios: an empty string, a string that equals the colored string for 'discolored': '0', and a type of decimal representation discolored string: '00'). Therefore, as soon as one of these conditions receives a match, it will automatically terminate the function and return 0. 

Only in the case where none of the previous conditions are fulfilled does the function reach its final lines, subsequently returning 'colored' or equivalent to the initial version of is_colored if it were given the same values.