char const *nextarg (char const *str)
{
  if (*args) 
  {
    bool r = strcmp(*args, str) ? false : true;
    if (r) args++;
    return r;
  }
  else 
  {
    return false;
  }
}