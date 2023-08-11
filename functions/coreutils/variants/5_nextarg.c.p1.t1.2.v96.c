bool nextarg (char const *str)
{
  bool r = (*args != nullptr) && STREQ (*args, str);
  args += r;
  return r;
}