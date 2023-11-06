nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool result = STREQ (*args, str);
  
  if (result)
      args += 1;
  
  return result;
}