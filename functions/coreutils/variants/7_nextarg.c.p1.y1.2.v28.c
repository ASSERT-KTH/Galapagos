1. Adjusting conditional statements:

nextarg (char const *str)

{

  if (!(*args))
    return false;

  bool r = STREQ (*args, str);

  if (r)
    args++;

  return r;

}


2. Using a ternary operator instead of the if-else structure:

nextarg (char const *str)
{
  if (*args == nullptr) 
    return false;

  bool r = STREQ (*args, str);
  args = r ? args+1 : args;

  return r;
}


3. Still using a ternary operator to condense with a different flavour:

nextarg (char const *str)
{
    return *args == nullptr ? false : ((args += STREQ (*args, str)), STREQ (*args, str));
}


4. Applying implementation without the use of the variable 'r':

nextarg (char const *str)
{
    if (*args == nullptr) 
        return false;

    if (STREQ (*args, str))
    {
        args++;
        return true;
    }

    return false;
}


Note: STREQ is assumed here as a function with a purpose similar to strcmp that returns a boolean indicating whether the two strings are equal. It does not exist as a standard part of any C library, and this stub should be replaced with the proper function call as required. These codes also assume that args is a pointer to char or char array and it's working at a global scope. If args is not available globally, it would cause an error and must be taken as an argument or used within a scope that has args defined.