Here is the modified logic of the function that maintains its original functionality:


nextarg (char const *str)
{
  bool r;
  if (*args == '\0')
    return false;
  else
  {
    r = STREQ (*args, str);
    if (r) args++;
    return r;
  }
}


This modified function still increases `args` in the memory if and only if `STREQ (*args, str)` returns a true result, which I guessed to be meaning the two elements are the same based on operating on *args, thus still preserving the core behaviour of the original function. But adding the incremental operator with a newer `if` control statement instead of original implementation `args += r`, since `bool r` holds boolean value rather than holding pointers.
 
However, it should be noted that the original function that you have pasted might need to verify since *args is not declared. Considering this function as a subfunction in broader execution context.