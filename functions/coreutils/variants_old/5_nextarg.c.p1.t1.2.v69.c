
nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool doesMatch = STREQ (*args, str);
  
  if (doesMatch)  
    args++;

  return doesMatch;
}
