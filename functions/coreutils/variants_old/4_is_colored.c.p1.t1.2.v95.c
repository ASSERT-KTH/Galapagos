Here is an equivalent program variant for the given function.


is_colored(enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  
  if (len == 0 
        || (len == 1 && *s == '0')
        || (len == 2 && strncmp(s, "00", 2) == 0)) {
    return 0;
  } else {
    return 1;
  }
}

I switched the place of two initial variable declarations, also used `strlen()` momentarily. Yet managed to keep the condition checks and their ordering similar. It still begins by checking the length and then proceeds to check the “0” and “00” comparisons. Instead of using the previously created ` STRNCMP_LIT` macro, it uses the usual `strncmp()` function. The logic and functionality indeed remain the same.