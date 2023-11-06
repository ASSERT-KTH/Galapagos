int nextarg (char const *str)
{
  int r = 0;
  if (*args != NULL)
  {
    r = STREQ (*args, str);  
    args += r;      
  }

  return r;
}