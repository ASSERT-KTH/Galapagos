bool nextarg (char const *str)
{
  if (!*args)
    return false;
    
  bool result = (strcmp(*args, str) == 0);
  args += result;
  
  return result;
}