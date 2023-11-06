nextarg (char const *str)
{
  if (!(*args))
    return false;
 
  bool r = (*args && STREQ (*args, str) ? true : false);
  if(r)
    args++; 

  return r;
}