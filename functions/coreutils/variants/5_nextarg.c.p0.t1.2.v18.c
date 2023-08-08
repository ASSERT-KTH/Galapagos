nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool r = (*args == str);
      args += r ? 1 : 0;
      return r;
    }
}