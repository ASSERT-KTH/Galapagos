nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool cmpResult = STREQ (*args, str);
      if(cmpResult)
         args++;
      return cmpResult;
    }
}