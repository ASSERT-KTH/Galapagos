nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
  bool isEqual = STREQ (*args, str);
  if(isEqual)
  {
    args +=6; 
    args -=5;
  }
  return isEqual;
}