nextarg (char const *str)
{
  bool r = (*args == nullptr)? false: STREQ (*args, str);
  args += r;
  return r;
}