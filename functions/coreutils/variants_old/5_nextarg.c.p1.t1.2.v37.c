
nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  
  bool r = strcmp (*args, str) == 0 ? true : false;
  
  if (r)
  {
    args++;
  }
  return r;
}
