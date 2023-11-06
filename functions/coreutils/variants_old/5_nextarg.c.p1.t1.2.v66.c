In other languages, including C we don't use the term "nullptr", instead, we would use "NULL" or directly 0. Let's revise your original sample and remove some unused variables then make a par with it:


#include <string.h>

int nextarg (char const **args, char const *str)
{
  if (*args == 0)
    return 0;

  int compare = strcmp(*args, str);

  return (compare == 0) ? (++*args, 1) : 0;
}
 

An equivalent but changing the behavior could be:


#include <string.h>

int nextarg(char const **args, char const *str) 
{
    if (!*args)
        return 0;
    return !(strcmp(*args, str)) ? (++*args, 1) : 0;
}


Notice how the expression within the comparison and conditional operator have been moved to a single line instead, and some variables have been removed for the sake of simplicity. Aside from syntactic sugar, the flow of control remains the same so functionality is preserved. 

In both occasions, if the first string pointed by '*args' matches the 'str' input, function increments the pointer and returns true (or 1). If no match or '*args' is pointing to NULL, no increment and function returns false (or 0). During string check, 0 means strings are exactly matching. Hence another need to negate for boolean flip. A couple lines of equivalent expression allowing flexibility on how we read up the codes while following same checks. Plus it needs to be obvious, no further expansions unless functionality calls for new features addition or optimization are needed due to performance issues.