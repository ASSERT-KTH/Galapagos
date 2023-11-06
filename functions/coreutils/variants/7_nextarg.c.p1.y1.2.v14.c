1. Change Variable Names

nextarg_1 (char const *input)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool equality_check = STREQ (*args, input);
      args += equality_check;
      return equality_check;
    }
}

2. Remove else Statement

nextarg_2 (char const *str)
{
  if (*args == nullptr)
    return false;

  bool result = STREQ (*args, str);
  args += result;
  return result;
}


3. Use Ternary Operator 

nextarg_3 (char const *str)
{
  return *args == nullptr ? false : ((args += STREQ (*args, str)), STREQ (*args, str));
}


4. Reverse Condition Statement

nextarg_4 (char const *str)
{
  if (*args != nullptr)
  {
      bool r = STREQ (*args, str);
      args += r;
      return r;
  }
  return false;
}
 
5. Removing Variable Declaration

nextarg_5 (char const *str)
{
  if (*args != nullptr)
    {
      args += STREQ (*args, str);
      return STREQ (*args, str);
    }
  return false;
}
 
   
Kindly note that on calling STREQ on this transformed function twice might result in bugs if STREQ have side effects or args pointer had been changed outside of the function.