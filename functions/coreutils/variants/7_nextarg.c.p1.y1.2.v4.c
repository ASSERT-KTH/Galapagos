1.

nextarg (char const *str)
{
  if (*args == NULL) {
    return false;
  } 

  bool r = STREQ (*args, str);
  args += r;
  return r;
}


2.

nextarg (char const *str)
{
  if (*args != NULL)
  {
      bool r = STREQ (*args, str);
      args += r;
      
      return r;
  }
  return false;
}

3.

nextarg (char const *str)
{
  bool r = false;
  
  if (*args != NULL)
  {
      r = STREQ (*args, str);
      args += r;
  }
  
  return r;
}

4.

nextarg (char const *str)
{
  bool r = (*args != NULL) ? STREQ (*args, str) : false;
  if(r) args += r;
  
  return r;
}
