Variant 1:


nextarg (char const *str)
{
  bool r = false;
  
  if (*args != nullptr)
  {   
      r = STREQ (*args, str);
      args += r;     
  }
    
  return r;
}


Variant 2:


nextarg (char const *str)
{
  if (*args != nullptr)
  {
    bool r = STREQ (*args, str);
    
    if(r)
        args ++;
        
    return r;
  }
  else
  {
    return false;
  }
}


Variant 3:


nextarg (char const *str)
{
  bool r;

  if (*args != nullptr)
  {
      r = STREQ (*args, str);
      args += (int)r;
  }
  else
  {
      r = false;
  }
    
  return r;
}
