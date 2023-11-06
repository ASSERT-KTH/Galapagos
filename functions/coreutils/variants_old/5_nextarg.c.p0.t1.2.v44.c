nextarg (char const *str)
{
  return *args
    ? ([&] { bool r = STREQ (*args, str); args += r; return r; }())
    : false;
}