nextarg (const char *str)
{
  if (*args == 0)
    return false;
  else
    {
      int r = STREQ (*args, str);
      args += r;
      return static_cast<bool>(r);
    }
}