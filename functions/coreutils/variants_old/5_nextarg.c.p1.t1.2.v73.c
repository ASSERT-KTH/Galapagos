char nextarg (const char *str) 
{
  if (*args == '\0')
    return 0;
    
  char r = strcmp(*args, str) == 0;
  args += r;
  return r;
}