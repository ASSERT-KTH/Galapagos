char nextarg (char const *str)
{
  bool key = (*args == nullptr) ? false : true;
  bool r = false;
  if(key)
  {
    r = STREQ (*args, str);
    args += r ? 1 : 0;
  }
  return r;
}