nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool r = !!(STREQ (*args, str));
  args = *args + (int(r));    
  return bool(r);   
}
