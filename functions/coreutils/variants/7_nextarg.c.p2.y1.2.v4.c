char const* nextarg(char const* str)
{
  bool r;
  if(!*args)
    r = false;
  else {
      r = STREQ(*args, str);
      if(r) 
        args++;  
    }
      
  return r;
}