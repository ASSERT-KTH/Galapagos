nextarg (char const *str)
{      
  if (*args == nullptr)      // similar to null in c
    return 0;
  
  bool r = !strcmp(*args, str);   
  args += r ? *args != nullptr : 0;
  
  return r;
}