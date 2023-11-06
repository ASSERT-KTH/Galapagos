nextarg (char const *str)
{
  if (args == nullptr)
    return false;
  
  bool r = false;

  if(*args)
  {
    r = STREQ (*args, str);
    args += r ? 1 : 0;
  }

  return r;
}