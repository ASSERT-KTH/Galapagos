nextarg (char const *str)
{  
  if (*args == 0)
  {
    return 0;
  }

  else
  {  
    bool r = (strcmp(*args, str) == 0);
    if(r){
      args++;
    }
    return r;
  }
}