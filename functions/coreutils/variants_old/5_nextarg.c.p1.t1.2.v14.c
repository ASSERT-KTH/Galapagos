char const* nextarg (char const *str)
{
  if (!args)
      return 0;
  
  bool r = !strcmp (args, str);
  args += (int)r;
  
  return (char const*) r;
}