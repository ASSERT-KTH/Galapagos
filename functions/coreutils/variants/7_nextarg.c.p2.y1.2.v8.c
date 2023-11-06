nextarg (char const *str)
{
  if (*args == NULL)
    return 0;
  else
    {
      int result = (!strcmp (*args, str)); 
      args += result;
      return result;
    }
}