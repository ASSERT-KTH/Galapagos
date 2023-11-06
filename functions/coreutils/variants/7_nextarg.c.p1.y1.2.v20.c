Variant 1:

nextarg (char const *str)
{
  if (*args == NULL)
    return 0;
  else
    {
      int r = strcmp (*args, str) == 0;
      args += r;
      return r;
    }
}
 

Variant 2:

nextarg (char const *str)
{
  if (!*args)
    return false;
  
  bool r = !strcmp (*args, str);
  args += r;
  return r;
}


Variant 3: 

nextarg (char const *str)
{
  if (*args == 0)
    return 0;

  bool resp;
  resp = (strcmp(*args, str) == 0) ? true : false;
  
  if(resp)
      ++args;

  return resp;
}


Variant 4:

nextarg (char const *str)
{
    bool r = false; 
    if (*args != nullptr)
    { 
        r = !strcmp (*args, str);
        args += r;
    }
    return r;
}
