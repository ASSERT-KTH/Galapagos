Here's another function implementation maintaining the signature while preserving the original functionality:


nextarg (char const *str)
{
  if (!args || !str) 
    return false;
  else 
  {
      bool r = STREQ (*args, str);
      args = r ? args + 1 : args;
      return r;
  }
}

In this variant, I check if any null value is passed (either *args or str is null). I've used a ternary operator where 'args' won't change its position if STREQ (*args, str) is false, preventing a possible out-of-bound error.