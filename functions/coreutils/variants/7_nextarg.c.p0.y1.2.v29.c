bool nextarg (char const *str)
{
  if (!*args)
    return false;

  bool r = !strcmp(*args, str);
  args += r;

  return r;
}