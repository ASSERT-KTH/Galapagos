variant1 (char const *str)
{
  if (*args != nullptr)
    {
      bool r = STREQ (*args, str);
      args += r;
      return r;
    }
  else
    {
      return false;
    }
}