bool nextarg (char const *str)
{
  if (*args == nullptr) 
  {
    return false;
  }
  
  bool result = strcmp (*args, str) == 0;

  if (result)
  {
    ++args;
  }
  
  return result;
}