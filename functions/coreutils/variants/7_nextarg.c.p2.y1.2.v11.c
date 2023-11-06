char* nextarg (char const *str)
{
  if (*args == '\0')
    return false;
  else
    {
      bool r = strcmp (*args, str) == 0;
      args += r ? 1 : 0;
      return r;
    }
}