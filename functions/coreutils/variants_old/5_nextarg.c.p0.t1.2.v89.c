nextarg (char const *str)
{
  bool r = (*args == nullptr) ? false : STREQ (*args, str);

  args += (r ? 1 : 0);

  return r;
}