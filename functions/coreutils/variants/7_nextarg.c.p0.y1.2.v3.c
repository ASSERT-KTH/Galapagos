bool nextarg (char const *str)
{
  if (*args == nullptr) {
    return false;
  }    
  
  bool str_match = strcmp(*args, str) == 0;
  args += str_match;
  return str_match;
}