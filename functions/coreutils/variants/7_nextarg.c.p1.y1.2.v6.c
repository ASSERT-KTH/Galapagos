Variant 1:

nextarg (char const *str) 
{
  bool r = *args != nullptr;

  if(r)
  {
      r = STREQ (*args, str);
      args += r;
  }
  return r;
}


Variant 2:

nextarg (char const *str)
{
    if (!*args)
    {
        return false;
    }
    else if (STREQ (*args, str))
    {
        ++args;
        return true;
    }
    else 
    {
        return false;
    }
}


Variant 3:

nextarg (char const *str) 
{
  if (*args == nullptr)
    return false;
  
  bool r = STREQ (*args, str);
  if (r)
  	args++;     
  return r;
}


Variant 4:

nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }

  int r = (STREQ (*args, str)) ? 1 : 0;
  args += r ;
  return (bool)r;
}
