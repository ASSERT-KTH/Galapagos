nextarg (char const *str)
{
  bool r;
  if (*args != nullptr) 
  {
    r = STREQ (*args, str);
    args += r;
  } 
  else 
  {
    return false;
  }  
  return r;
}