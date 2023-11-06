char* nextarg (char const *str)
{
  if (args == NULL)
    return NULL;
    
  bool result = strcmp (*args, str) == 0;
  args += result ? 1 : 0;

  return result? *args: NULL;
}