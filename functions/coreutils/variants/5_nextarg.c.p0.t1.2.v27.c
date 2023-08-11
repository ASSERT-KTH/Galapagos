nextarg (char const *str)
{
  if (*args == NULL)
  {
    return false;
  }
  else 
  {
    bool resultValue = (strcmp(*args, str) == 0);
    args += resultValue;
    return resultValue;
  }
}