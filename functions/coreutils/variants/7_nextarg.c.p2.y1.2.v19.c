char const* nextarg (char const *str)
{
  if (!*args)
    return NULL;
  else
    {
      bool isEqual = strcmp(*args, str) == 0;
      args += isEqual;
      return isEqual ? args : NULL;
    }
}