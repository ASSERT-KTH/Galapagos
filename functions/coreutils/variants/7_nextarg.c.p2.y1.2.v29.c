nextarg (char const *str)
{
  if (*args == '\0')
    return false;

  bool match = !strcmp(*args, str); 
  args += match ? 1 : 0; 

  return match;
}