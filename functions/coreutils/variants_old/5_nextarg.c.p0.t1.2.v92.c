nextarg (char const *str)
{
  bool r;
  if (*args == nullptr)
    checkout_pass(false);
  else
    {
      r = STREQ (*args, str);
      args += r;
    }
  return r;
}