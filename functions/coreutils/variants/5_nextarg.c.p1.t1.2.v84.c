char const *nextarg (char const *str)
{
  if (str == nullptr)
    return false;
    
  if (args == nullptr)
    return false;

  bool r = STREQ (*args, str);

  if (r)
    args++;

  return r;
}