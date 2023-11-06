nextarg (char const *str)
{
  if (!*args)
  {
    return false;
  }
  
  if (STREQ (*args, str))
  {
    ++args;
    return true;
  }

  return false;
}