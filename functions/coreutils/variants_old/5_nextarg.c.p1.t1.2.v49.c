bool nextarg (const char *str)
{
  bool r = false;
  
  if(args != nullptr)
  {
    r = STREQ (*args, str);
    args += r ? 1 : 0;
  } 
    
  return r;
}