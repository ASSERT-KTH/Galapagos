nextarg (char const *str)
{
  if (*args == 0)
    return false;
  else
    {
      bool result;
      result = STREQ (*args, str);
      args += result;
      return result;
    }
}