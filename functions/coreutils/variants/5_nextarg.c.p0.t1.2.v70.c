nextarg (char const *str)
{
  bool check;
  if (!*args)
    check = false;
  else
    {
      check = STREQ (*args, str);
      args += check;
    }
  return check;
}