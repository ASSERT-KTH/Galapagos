nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  if (STREQ (*args, str) == true)
  {
    args++;
    return true;
  }
  return false;
}