Code variant:


nextarg (char const *str)
{
  if (*args == '\0')  // checking for null character
    return 0;
  else
    {
      bool r = STREQ (*args, str);
      if(r)
          args += 1;
      return (int)r; // return int instead of bool
    }
}
