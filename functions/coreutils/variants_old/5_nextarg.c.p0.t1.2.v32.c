nextarg (char const *str)
{
  if (*args == NULL)
    return 0;
  else
    {
      bool r = STREQ (*args, str);
      args += r ? 1 : 0;
      return r ? true : false;
    }
}