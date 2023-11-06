bool nextarg (char const *str)
{
  if (!*args)
      return 0;
  
  if (STREQ (*args, str))
  {
    args++;
    return 1;
  }

  return 0;
}