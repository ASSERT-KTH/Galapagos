int nextarg (const char *str)
{
  return (*args != nullptr) ? ((args += STREQ (*args, str)) != 0): 0;
}