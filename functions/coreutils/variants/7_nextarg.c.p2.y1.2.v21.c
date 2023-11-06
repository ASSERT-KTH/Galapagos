nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool r = (*args == str) ? true : false;
      if (r)
        args++;
      return r;
    }
}