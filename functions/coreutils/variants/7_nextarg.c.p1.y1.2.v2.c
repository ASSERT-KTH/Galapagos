1. Inline variable `r`:


nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      args += STREQ (*args, str);
      return STREQ (*args, str);
    }
}


2. Using ternary operator:


nextarg (char const *str)
{
  return *args == nullptr ? false : (args += STREQ (*args, str), STREQ (*args, str));
}


3. Splitting the if-else condition:


nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
    
  bool r = STREQ (*args, str);
  args += r;
  return r;
}


4. Single return statement:


nextarg (char const *str)
{
  bool r = false;
  if (*args != nullptr)
  {
    r = STREQ (*args, str);
    args += r;
  }

  return r;
}


5. Enclosing operations in parentheses:


nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool r = (STREQ (*args, str));
      args += (r ? 1 : 0);
      return (r != 0);
    }
}
