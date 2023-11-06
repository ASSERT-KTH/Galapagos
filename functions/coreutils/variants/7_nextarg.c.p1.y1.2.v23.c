1.

char nextarg(const char* str)
{
  if (*args == '\0')
    return '\0';
  else
    {
      bool r = STREQ(*args, str);
      args += r;
      return r;
    }
}


2.

char nextarg(char const *str)
{
  if (*args == NULL)
    return 0;

  bool r = STREQ(*args, str);
  if(r) args++;
  return r;
   
}


3.

char nextarg(char const *str)
{
  bool r = (*args != NULL) && STREQ(*args, str);
  args += r;
  return r;
}


Note: Functions 'STREQ' and 'args' are not clearly defined in the provided original function. Throughout these transformations, I have considered 'STREQ' to be a function used for comparison (like that of strcmp from string.h in C) and considered 'args' as a pointer to an argument array. You must replace 'STREQ' and 'args' as per your context and available functions and variables.
