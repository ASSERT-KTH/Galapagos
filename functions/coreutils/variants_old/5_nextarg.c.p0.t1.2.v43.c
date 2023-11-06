nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  else 
  {
    bool checkEqual = STREQ (*args, str);
    if (checkEqual)
    {
      args++;
    }
    return checkEqual;
  }
}