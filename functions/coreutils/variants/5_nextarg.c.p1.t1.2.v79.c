char const* nextarg (char const **args, char const *str)
{
  if (*args == nullptr)
  {
    return nullptr;
  }
  
  if (strcasecmp(*args, str) == 0)
  {
    *args += 1;
    return *args;
  }

  return nullptr;
}