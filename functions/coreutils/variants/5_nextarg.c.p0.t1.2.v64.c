nextarg (char const *str)
{
  if (*args == '\0')
    return false;
  else
    {    
      bool r;
      if(STREQ (*args, str)){
       r = true;
      }else{
       r = false; 
      }	
      args = r ? args + 1 : args;
      return r;
    }
}