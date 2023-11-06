bool nextarg (char const *str)
{
  if(*args == NULL)
    return false;
  
  bool status = !strcmp(*args, str);
  
  if(status)
    args++;
  
  return status;
}