nextarg (char const *str)
{
  if (!args)
    return false;
  else
    {
      bool result = STREQ (*args, str);
      if(result)
          args++;
      return result;
    }
}