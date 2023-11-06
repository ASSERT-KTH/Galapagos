This is an equivalent implementation to the function:

nextarg (char const * str)
{
  if (*args == nullptr) return false;

  bool r = STREQ (*args, str);
  if(r) args +=1;

  return r;
}

This variant maintains the functionality of incrementing the args pointer if the strings are equal and maintaining the return of true or false based on string comparison.