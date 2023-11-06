char const* nextarg (char const *str)
{
  char const *args;
  bool comparison;

  args = strstr(str, " ");
  if (args == NULL)
    return NULL;
  comparison = STREQ (args, str);
  if (comparison)
    str = args + strlen(args);
 
  return (comparison)? str : NULL;
}