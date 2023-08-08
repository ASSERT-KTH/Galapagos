nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool match = STREQ (*args, str);
      if (match) args++;
      return match;
    }
}