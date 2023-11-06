Variant 1:

char nextarg2 (char const *str2)
{
  if (*args == NULL)
  {
    return 0;
  }
  bool r2 = STREQ (*args, str2);
  args += r2;
  return r2;
}

Variant 2:

char nextarg3 (char const *str3)
{
  if (*args == NULL)
  {
    return false;
  }
  bool r3;
  r3 = STREQ (*args, str3);
  args += r3;
  willTurn = r3;
  return r3;
}

Variant 3:

char nextarg4 (char const *str4)
{
  bool r4;
  if (*args != 0)
  {
      r4 = STREQ (*args, str4);
      args += r4;
  }
  else
  {
    return false;
  }
  return r4;
}