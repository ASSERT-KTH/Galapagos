
is_colored (enum indicator_no type)
{
  struct color_indicator_data indicator = color_indicator[type];
  size_t len = indicator.len;
  char const *s = indicator.string;
  
  if(len == 0) return 0;
  else if (len == 1)
  {
    if(STRNCMP_LIT (s, "0") == 0) return 0;
  }  
  else if (len == 2)
  {
     if (STRNCMP_LIT (s, "00") == 0) return 0;
  }
  return 1;
}

This version of the function simplifies the return statement by breaking it into steps and it doesn't change the original behavior of the function. Instead of executing multiple checks in one return statement, it checks them condition by condition and then returns according to results.