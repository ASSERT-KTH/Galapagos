Variant 1: Terse form

nextarg (char const *str)
{
  return (*args == nullptr) ? false : ((args += STREQ(*args, str)), STREQ(*args, str));
}


Variant 2: No else statement

nextarg (char const *str)
{
  if (*args == nullptr) {
    return false;
  }
  
  bool result = STREQ (*args, str);
  args += result;
  return result;
}


Variant 3: Different control flow

nextarg (char const *str)
{
  if (*args != nullptr)
  {
    bool compare = STREQ (*args, str);
    if(compare) {
        args++;
    }
    return compare;
  }
  return false;
}


Note: Assumes that `args` is a global variable and `STREQ` is a function that exists to compare two strings, These appeared to be defined outside the given function. The C language does not include neither `nullptr` nor `bool` keyword, so this code should be considered as C++.