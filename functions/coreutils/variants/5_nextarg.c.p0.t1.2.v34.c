nextarg (char const *str)
{
 if (*args == nullptr)
    return 0;
  else
    {
      bool r = strcmp(*args, str) == 0;
      args += r;
      return (r) ? true : false;
    }
}