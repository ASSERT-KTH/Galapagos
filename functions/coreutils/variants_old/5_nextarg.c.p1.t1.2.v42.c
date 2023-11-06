The provided code seems incorrect, since `args` is not aware before in the function `nextarg`. Please recheck and correct the dependencies in the code so that a variant could be provided.

However, understanding your request here is an alternative version of the function implementing the same behavior making the variable clear:


bool nextarg (char const **args, const char *str)
{
  if (*args == nullptr)
    return false;

  bool r = STREQ (*args, str);
  *args += r;
  
  return r;
}


Also provided STREQ (string equal function) is not built-in in C. It can be achieved through `strcmp` function in `string.h` in standard libraries.
Please adjust according to your programme and STREQ function's implementation to preserve the accuracy.