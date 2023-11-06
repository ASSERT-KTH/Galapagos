nextarg (char const *str)
{
  bool result;

  // If args point to null, return false
  if (*args == nullptr)
    return false;
  else
  {
  	// Compare the string pointed at by args and str
    result = STREQ (*args, str);  

    if (result == true)
      args++;
      
    return result;
   }
}