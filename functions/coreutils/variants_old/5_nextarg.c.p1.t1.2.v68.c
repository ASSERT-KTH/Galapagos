char const* nextarg (char const *str)
{
  bool result = (*args != nullptr) && STREQ (*args, str);
  
  if(result)
    args++;
      
  return result;
}