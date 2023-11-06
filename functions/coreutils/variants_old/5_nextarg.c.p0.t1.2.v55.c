nextarg (char const *str)
{
  bool rtn = false;

  if (*args != nullptr)
    {
      rtn = STREQ (*args, str);
      args += rtn;
    }

  return rtn;
}