The program variant that changes the behavior while maintaining its original functionality:


nextarg(char const *str)
{
  if (*args == '\0') 
    return false;
  
  int point = STREQ (*args, str); 
  args += point; 
  return point > 0;
   
}
