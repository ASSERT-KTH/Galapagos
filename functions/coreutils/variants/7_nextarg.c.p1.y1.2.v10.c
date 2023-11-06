Variant 1:


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


Variant 2:


nextarg (char const *str)
{
  bool r = *args == nullptr ? false : STREQ (*args, str);
  if (r)
    args += 1;
  return r;
}


Variant 3:


nextarg (char const *str)
{
  bool r = (*args != nullptr && STREQ (*args, str)) ? true : false;
  if (r)
    args++;
  return r;
}


Variant 4:


nextarg (char const *str)
{
  if (*args != nullptr && STREQ (*args, str))
  {
      args++;
      return true;
  }
  return false;
}
