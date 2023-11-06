nextarg (char const *str)
{
  if (args[0] == '\0')
    return false;
  else 
    {
      bool r = STREQ (args, str);
      args += (int)r;
      return r;
    }
}