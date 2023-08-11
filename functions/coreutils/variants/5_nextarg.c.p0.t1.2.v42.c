nextarg (char const *str)
{
  if (*args) {
    bool r = STREQ (*args, str);
    if (r) {
       args++;
    }   
    return r;
  } 
  else {
    return false;  
  }   
}