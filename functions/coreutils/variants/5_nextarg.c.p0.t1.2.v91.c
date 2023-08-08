nextarg (char const *str)
{
  if (*args == 0)
  {
    return false;
  }
  else
  {
    bool equality = !strcmp (*args, str);
    if (equality)
      args++;
    return equality;
  }
}