nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool result = STREQ (*args, str);
      if (result)
      {
          args++;
      }   
      return result;
    }
}