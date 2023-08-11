nextarg (char const *str)
{
  if (*args == '\0')
    return false;
  else
    {
      bool r = STREQ (*args, str);
      ++args;
      return r;
    }
}