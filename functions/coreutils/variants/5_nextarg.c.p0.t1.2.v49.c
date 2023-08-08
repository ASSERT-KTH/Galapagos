nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool r = STREQ (*args, str);
      if(r)
      	args++;
      return r;
    }
}