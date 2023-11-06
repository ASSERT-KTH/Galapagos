bool nextarg (char const *str)
{
  if (*args == '\0')
      return false;
          
  bool r = (strcmp(args, str) == 0);
  args += r;
  return r;
}