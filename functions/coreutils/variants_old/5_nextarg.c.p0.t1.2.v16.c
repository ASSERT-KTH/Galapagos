nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool r = STREQ (*args, str);
      args += r;
      if (r)
        return true;
      else
        return false;
    }
}