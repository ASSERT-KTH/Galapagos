bool nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  bool compareResult = STREQ (*args, str);
  if (compareResult)
  {
      args++;
  }
  return compareResult;
}