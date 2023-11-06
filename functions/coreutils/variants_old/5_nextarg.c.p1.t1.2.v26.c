bool nextarg (const char *str)
{
  if (!*args) return false;

  bool r = strcmp (*args, str) ? false : true;
  if (r) args++;
   
  return r;
}