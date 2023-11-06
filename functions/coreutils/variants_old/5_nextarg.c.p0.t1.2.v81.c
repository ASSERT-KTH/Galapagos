nextarg (char const *str)
{
  if (*args != nullptr)
  { 
    bool result = STREQ (*args, str);
    args += result;
    return result;
  }
  else
  {
    return false;
  }
}