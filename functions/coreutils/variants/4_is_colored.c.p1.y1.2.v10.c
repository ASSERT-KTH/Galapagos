1. Using ternary operators:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return (len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0)) ? 0 : 1;
}


2. Avoiding negation:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return (len != 0 && (len != 1 || STRNCMP_LIT (s, "0") != 0) && (len != 2 || STRNCMP_LIT (s, "00") != 0)) ? 1 : 0;
}


3. Checking length first:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  if(len == 0) return 0;
  char const *s = color_indicator[type].string;
  if((len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0)) return 0;
  return 1;
}


4. Using braces instead of parentheses:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return ! {len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0)};
}


5. Using a single return statement:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return ! (!len || len == 1 && STRNCMP_LIT (s, "0") == 0 || len == 2 && STRNCMP_LIT (s, "00") == 0);
}


Please note: Not using brackets in C could lead to readability problems, it is generally not recommended.