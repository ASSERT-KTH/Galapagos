nextarg (char const *str)
{
  if (args[0] == '\0')
    return false;

  bool match = STREQ (args, str);
  if (match) args++;
  
  return match;
}