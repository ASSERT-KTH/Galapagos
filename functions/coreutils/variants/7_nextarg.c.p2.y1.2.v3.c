nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  
  bool r = (*args && STREQ (*args, str));
  
  args += r ? 1 : 0;
  return r;
}