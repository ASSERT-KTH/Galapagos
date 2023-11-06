nextarg (char const *str)
{
  if (args[0] == '\0')
    return false;
  else
    {
      bool r = STREQ (args, str);
      args += r ? 1 : 0;
      return r;
    }
}