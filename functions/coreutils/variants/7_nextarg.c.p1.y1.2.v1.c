Variant 1:

nextarg (char const *str)
{
  if (*args == NULL)
    return false;
  else
    {
      bool r = STRCMP (*args, str) == 0 ? true : false;
      args += r;
      return r;
    }
}


Variant 2:

nextarg (char const *str)
{
  if (!*args)
    return false;
  else
    {
      bool r = (!strcmp(*args, str)) ? true : false;
      args += r;
      return r;
    }
}


Variant 3:

nextarg (char const *str)
{
  if (*args == 0)
    return false;
  else
    {
      bool r = (!strcmp(*args, str));
      args += r ? 1 : 0;
      return r;
    }
}


Variant 4:

nextarg (char const *str)
{
  bool r = false;
  if (*args)
    {
      r = STRCMP (*args, str) == 0;
      args += r ? 1 : 0;
    }
  return r;
}
