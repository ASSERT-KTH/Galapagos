nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }

  bool r = !strcmp (*args, str);

  if (r)
  {
    args++;
  }

  return r;
}