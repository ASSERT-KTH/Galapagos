1. Using Ternary Operator

nextarg (char const *str)
{
  return (*args == nullptr) ? false : ((STREQ (*args, str)) ? (args++, true) : false);
}


2. Simplifying if else block

nextarg (char const *str)
{
  if (*args != nullptr) {
      bool r = STREQ (*args, str);
      if (r) args++;
      return r;
  }
  return false;
}


3. Swapping null condition

nextarg (char const *str)
{
  if (*args != nullptr) {
      bool r = STREQ (*args, str);
      args += r;
      return r;
  }
  return false;
}


4. Using shorthand if to increment args

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool r = STREQ (*args, str);
  *args += r ? 1 : 0;
  
  return r;
}


5. Return right away if args is null

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool r = STREQ (*args, str);
  args += r ;
  
  return r;
}
