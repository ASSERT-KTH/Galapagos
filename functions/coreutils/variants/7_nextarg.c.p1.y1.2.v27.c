Alternative 1: Using ternary operator

nextarg (char const *str)
{
  return (*args == nullptr) ? false : ( args += STREQ (*args, str), STREQ (*args, str) );
}


Alternative 2: Removing else and adding early returns

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool result = STREQ (**args, str);
  args += result;

  return result;
}


Alternative 3: Inline variables

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  return args += STREQ (*args, str), STREQ (*args, str);
}


Alternative 4: Single line expression

nextarg (char const *str)
{
  return *args != nullptr ? ( args += STREQ (*args, str), STREQ (*args, str) ) : false 
}


Note: These all examples are dependent on the fact that `args` are valid C String. Otherwise it will lead to Undefined Behavior.

This also depends on the function `STREQ` which compares two strings and returns a boolean indicating if they are the same or not, function definition not provided. 

Additionally, `args` pointer seems to missing or its something global not provided, It's currently being direct referenced `*args`, so examples are assuming direct dereference and there's `args` maintained with something global not given context.