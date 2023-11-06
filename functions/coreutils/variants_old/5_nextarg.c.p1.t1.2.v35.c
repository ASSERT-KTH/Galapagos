bool nextarg (char const *str)
{
  bool r = (*args == nullptr) ? false : STREQ (*args, str);
  
  if (r) args++;

  return r;
}