char const * nextarg (char const *str)
{
  if (str == nullptr)
    return 0;
  else
    {
      bool result = STREQ (args, str);
      
      if(result) args++;

      return str;
    }
}