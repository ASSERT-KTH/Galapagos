nextarg (const char *str)
{
  if (*args == nullptr)
    return 0;
  else
    {
      bool result = strcmp(*args, str) == 0;
      args += (int) result;
      return result;
    }
}