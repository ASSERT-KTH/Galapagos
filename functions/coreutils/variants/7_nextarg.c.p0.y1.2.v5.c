Here is an alternate version of the function:


nextarg (char const *str)
{
  if (*args != nullptr)
  {
       if (STREQ (*args, str)) 
       {
           args++;
           return true;
       }
       return false;
  }
  else
  {
      return false;
  }
}
