char const *nextarg (char const *str, char const **args)
{
  if (*args == nullptr) 
  {
    return nullptr;
  }
  
  if (strcmp(*args, str) == 0){
    *args += 1;
    return *args;
  }
  
  return nullptr;
}