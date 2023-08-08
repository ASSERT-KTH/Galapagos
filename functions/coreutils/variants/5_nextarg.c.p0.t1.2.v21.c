nextarg (char const *str)
{
  if (!(*args)) // change nullptr to !(*args)
    return false;
  else
    {
      bool checkVal; // initialize a variable to store the STREQ comparison result 
      checkVal = STREQ (*args, str); // assign the comparison result
      args += checkVal;
      return checkVal;
    }
}