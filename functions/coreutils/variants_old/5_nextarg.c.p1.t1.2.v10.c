char* nextarg (const char* str)
{
  if (*args == 0)
    return 0;
  else
    {
      bool isEqual = strcmp(*args, str) == 0;
      args += isEqual ? 1 : 0;
      return isEqual;
    }
}