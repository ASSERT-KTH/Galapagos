Option 1:

nextarg (char const *str)
{
  if (*args != nullptr)
  {
    bool r = STREQ (*args, str);
    args += r;
    return r;
  }
  return false;
}


Option 2:

nextarg (char const *str)
{
  return *args == nullptr ? false : ((*(args += STREQ (*args, str)) == str)) ;
}


Option 3:

nextarg (char const *str)
{
  bool r = false;

  if(*args != nullptr) {
     r = STREQ (*args, str);
     args = args + r;
  }
                                    
  return r;
}


Option 4:

nextarg (char const *str)
{
  bool r = (*args != nullptr) ? STREQ (*args, str) : 0;
  args = args + r;
  return r;
}
