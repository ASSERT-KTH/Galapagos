
nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }

  bool result;
  
  if (STREQ (*args, str)) 
  {
    result = true;
    ++args;
  }
  else 
  {
    result = false;
  }

  return result;
}
