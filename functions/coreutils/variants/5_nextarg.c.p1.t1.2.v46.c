char const* nextarg (char const* str)
{
  if (str == nullptr)
    return nullptr;

  static char const** args = nullptr;
  bool r = false;

  if(args != nullptr && *args != nullptr)
  {
    r = (strcmp(*args, str) == 0);
    if(r)
      args++;
  }

  return (r ? str : nullptr);
}