bool nextarg(char const *str)
{
  if(!args)
    return false;
  else
  {
    bool check = STREQ (*args, str);

    if(check)
    {
      args += 1;
    }
   
   return check;
  }
}