nextarg(char const *str)
{
  if (!*args) 
    return false;

  bool r = (strcmp(*args, str) == 0);
  args += r;
  return r;
}