nextarg (char const *str)
{
  if (args == nullptr) 
    return false;
  else 
    {
      int temp = *args == nullptr ? false : STREQ(*args,str);

      if (temp)
        args++; 

      return temp != 0;
    }
}