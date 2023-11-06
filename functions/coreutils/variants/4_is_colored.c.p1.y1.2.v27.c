1. Check variable attributes directly and return boolean.


is_colored (enum indicator_no type)
{
  return color_indicator[type].len != 0 && 
    !(color_indicator[type].len == 1 && STRNCMP_LIT (color_indicator[type].string, "0") == 0) && 
    !(color_indicator[type].len == 2 && STRNCMP_LIT (color_indicator[type].string, "00") == 0);
}


2. Split complex conditional into multiple checks.


is_colored (enum indicator_no type)
{
    if(color_indicator[type].len == 0) 
        return 0;

    if(color_indicator[type].len == 1 && STRNCMP_LIT (color_indicator[type].string, "0") == 0) 
        return 0;
      
    if(color_indicator[type].len == 2 && STRNCMP_LIT (color_indicator[type].string, "00") == 0) 
        return 0;

    return 1;
}


3. Replace C-style returning of boolean with C++ keywords.


bool is_colored (enum indicator_no type) 
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if (len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0))
    return false;
    
  return true;
}

Note: This is assuming that the color_indicator array and the enum are defined with the values. The strncasecmp_lit function is also defined and working correctly.

Sketchup:
- Implement C boolean checks;
- replace true with 1 and false with 0;
- structure checks as a series of if statements, returning immediately