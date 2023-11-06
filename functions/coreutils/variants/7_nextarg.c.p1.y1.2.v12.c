1. Using different structure:


nextarg (char const *str)
{
  if (*args != nullptr)
  {
     bool r = STREQ (*args, str);
     args += r;
     return r;
  }
  return false;
}


2. Using short circuit evaluation technique:


nextarg (char const *str)
{
  return *args != nullptr && (args += STREQ (*args, str)) && STREQ (*args, str);
}


3. Using another flow control mechanism:


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


4.Reversing the condition


nextarg (char const *str)
{
  if (!*args) return false;
 
  bool r = STREQ (*args, str);
  args += r;
  return r;
}
