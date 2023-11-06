bool nextarg (char const *str) 
{
  if (*args != nullptr)
  {
    bool r = STREQ (*args, str);
    args += r;
    return r;
  }
  return false;
}