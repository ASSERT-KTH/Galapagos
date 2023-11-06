1. Slight Changes in Conditions


is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return ! ((len == 1 && !STRNCMP_LIT (s, "0")) 
            || (len == 2 && !STRNCMP_LIT (s, "00"))
            || len == 0);
}


2. Using Ternary Operator


is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return (len == 0
            || (len == 1 && STRNCMP_LIT (s, "0") == 0)
            || (len == 2 && STRNCMP_LIT (s, "00") == 0)) 
            ? 0 : 1;
}


3. Return As You Go Style


is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0) {
    return 0;
  }
  else if (len == 1 && STRNCMP_LIT (s, "0") == 0) {
    return 0;
  }
  else if (len == 2 && STRNCMP_LIT (s, "00") == 0) {
    return 0;
  }
  else {
    return 1;
  }
}


4. Separate If Statements


is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0) {
    return 0;
  }
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) {
    return 0;
  }
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) {
    return 0;
  }
  return 1;
}


5. Inverting the Overall Condition


is_colored(enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    if (len > 0 && ((len != 1 || STRNCMP_LIT(s, "0") != 0) 
                    && (len != 2 || STRNCMP_LIT(s, "00") != 0)))
        return 1;
    else 
        return 0;
}
