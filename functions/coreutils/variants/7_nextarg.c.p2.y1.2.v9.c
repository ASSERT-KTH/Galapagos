char *nextarg (char const *str)
{
  if (*args != nullptr)
  {
    bool result = STREQ (*args, str);

    if (result)
        args += 1;
    
    return result;
  }
  else
  {
    return false;
  }
}