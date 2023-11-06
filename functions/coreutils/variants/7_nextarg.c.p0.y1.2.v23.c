
nextarg (char const *str)
{
  bool result = false;

  if (*args != nullptr)
  {
    result = STREQ (*args, str);
    args += result;
  }

  return result;
}
