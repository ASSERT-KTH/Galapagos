nextarg (char const *str)
{
  if (*args == 0)
    return false;
  else
    {
      bool r = STREQ (*args, str);
      if (r) 
        args++;
      else
        args = args;
      return r;
    }
}