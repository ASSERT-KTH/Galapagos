nextarg (char const *str)
{
  if (*args == 0)
    return false;
  else
    {
      bool flag = STREQ (*args, str);
      args += flag ? 1 : 0;
      return flag;
    }
}