nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return 0;
  }
  else
  {
    bool result;
    result = STREQ (*args, str);
    args = args + result;
    return result;
  }
}