
nextarg (char const *str)
{
  bool r = (*args != nullptr) && STREQ (*args, str);
  if (r)
  {
    args++;
  }
    
  return r;
}


This variant follows the original functionality but diffuses the design, streamlining the step where it checks the current argument against `nullptr` and the comparison of `*args` to `str` into a single line. It only increments `args` in case both conditions are met, rather than always when none of them are false.