nextarg (char const *str)
{
  if (*args == 0)
     return false;
  else
    {
      int r = STREQ (*args, str) ? 1 : 0;
      args += r;
      return static_cast<bool>(r);
    }
}