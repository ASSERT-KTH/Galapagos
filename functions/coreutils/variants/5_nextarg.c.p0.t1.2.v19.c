nextarg (char const *str)
{
  if (!*args)
    return false;
  else
    {
      auto result = STREQ (*args, str) != 0; 
      if (result) args += 1; 
      return result;
    }
}