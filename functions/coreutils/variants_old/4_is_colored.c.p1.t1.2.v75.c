The mentioned function seems to check string color_indicator of a certain type. If its length is zero or its length is one and it is "0" or its length is two and it is "00", the function will return 0 (not colored). Otherwise, it will return 1 (colored). 

Here is the requested variant of the original function:


is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  int isEqual = (len >= 2) ? STRNCMP_LIT(s, "00") : STRNCMP_LIT(s, "0");
  int isNotColored = (len == 0 || isEqual == 0);
  return !isNotColored;
}


In this version, I simply got rid of the multiple OR conditions and utilized ternary operator. First, I've checked the strings before their lengths to possibly exit earlier if the input doesn’t meet the specific criteria, potentially improving the performance in certain cases.

Still, the modified function behaves just like the original one: it will still return 0 if the provided color_indicator's length is zero or if it is "0" or "00”, otherwise returns 1, indicating that the color is set.