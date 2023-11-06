nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }

  bool r = false;

  if(STREQ (*args, str))
  {
    r = true;
    args++;
  }
  
  return r;
}