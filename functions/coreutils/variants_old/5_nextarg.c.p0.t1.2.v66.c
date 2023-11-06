nextarg (char const *str)
{
  if (!(*args))
      return false;
  else
  {
      bool res = STREQ (*args, str);
      if(res)
          args++;
      return res;
  }
}