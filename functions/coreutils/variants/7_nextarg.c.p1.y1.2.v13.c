Variant 1:

nextarg (char const *str)
{
  if (!*args)
    return false;
  
  bool result = STREQ (*args, str);
  args += result;
      
  return result;
}


Variant 2:

nextarg (char const *str)
{
  if (*args == nullptr) return false;

  bool isEqual = STREQ (*args, str);
  if (isEqual) args++;

  return isEqual;
}


Variant 3:

nextarg (char const *str)
{
  bool isStrEquivalent = false;

  if (*args != nullptr)
    {
      isStrEquivalent = STREQ(*args, str);
      args += isStrEquivalent;
    }

  return isStrEquivalent;
}


Variant 4:

nextarg (char const *str)
{
  if (*args != nullptr)
    {
      bool isEqual = STREQ(*args, str);
      
      if (isEqual)
        args++;  
      
      return isEqual;
    }

 return false; 
}

Variant 5:

nextarg (char const *str)
{
  if (*args == nullptr)
   return false;

  if(STREQ (*args, str))
    {
      args++;
      return true; 
     }
  
  return false; 
}
