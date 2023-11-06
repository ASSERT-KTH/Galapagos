bool nextarg (char const *str)
{
  bool r;
  if (*args == nullptr)
    r = false;
  else
    {
      r = STREQ (*args, str);
      args += r;
    }
  return r;
}