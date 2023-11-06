int nextarg (char const *str)
{
  if (*args == '\0')
    return 0;
  else
    {
      int comparison = strcmp(*args, str) == 0;
      args += comparison;
      return comparison ? 1 : 0;
    }
}