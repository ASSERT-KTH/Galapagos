nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool r = (*args != nullptr) && STREQ(*args, str);
  if (r)
      args++;

  return r;
}