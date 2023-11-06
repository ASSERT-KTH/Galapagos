nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      if (STREQ (*args, str))
      {
        args++;
        return true;
      }
      else
        return false;
    }
}