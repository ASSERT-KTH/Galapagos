nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  
  bool r = STREQ (*args, str);

  if (r) args += 1;

  return r;
}