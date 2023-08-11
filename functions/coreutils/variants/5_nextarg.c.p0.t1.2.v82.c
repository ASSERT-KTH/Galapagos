nextarg (char const *str)
{
  if (*args == NULL)
  {
    return false;
  }
  else
  {
    int r = !strcmp(*args, str);
    args = args + r;
    return r != 0;
  }
}