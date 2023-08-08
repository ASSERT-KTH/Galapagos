Here is a program variant of the original function:

nextarg(char const *str)
{
  if (*args == nullptr) {
    return false;
  }
  else {
    bool r = STREQ (*args, str);
    /* After comparison move to the next argument regardless */
    args++;
    
    /* Only return the comparison result */
    return r;
  }
}

This variant of the function does the same as the original, but it does it in a slightly different manner: comparing `*args` to `str` and moving to next argument regardless of comparison result, and then only returning the result of comparison.