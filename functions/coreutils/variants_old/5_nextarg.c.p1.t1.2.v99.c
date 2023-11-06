char const * args; // global string pointer variable with identifier "args"

bool nextarg (char const *str)
{
  bool result = false; // temporary boolean variable

  if (args && *args)  // check if args contains address and its reference value is non-null
  {
    // strcmp() returns 0, if *args and str are identical
    // set 1 to the result if the strings are identical and set 0 otherwise   
    result = (strcmp(args, str) == 0 ? true : false);
    
    if(result)  // if result is true, the pointer is advanced to next character
      args++;
  }

  // return the comparison result
  return result;
}