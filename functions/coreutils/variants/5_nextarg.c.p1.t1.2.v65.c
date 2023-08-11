
nextarg (char const *str)
{
  if (!*args)
    return false;

  bool r = !strcmp(*args, str);
  
  if (r)
    args++;
  
  return r;
}
