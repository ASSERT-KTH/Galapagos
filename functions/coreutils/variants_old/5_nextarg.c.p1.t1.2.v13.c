The provided function seems to have some missing elements and doesn't compile correctly as it is. `args` variable is not defined and the same for STREQ function too. So assuming STREQ is a macro for comparing two strings, args is char const** representing an array of strings, and this function is aimed to be used for checking if a specific string is the next argument for some command (like in a CLI application), here's a possible variation to it:


bool nextarg (char const **args, char const *str)
{
  if (*args == nullptr)
    return false;
    
  if (strcmp(*args, str) == 0)
  {
    ++args;
    return true;
  }
  
  return false;
}

In this variation, the function first checks if `*args` is `nullptr`. If true, it returns false. If not, it checks whether the string pointed to by `*args` matches `str` through a call to the `strcmp` function. If they match (`strcmp` returns 0), the function increments `args` pointer value to point to the next string (if any) and returns true. If they don't match, it just returns false.
Note that this function implements the same functionality the original function seems supposed to provide, but with clearer code. Also remember that to use `strcmp` function, you must `#include <cstring>` in your .cpp file. 

Lastly, remember that you should exercise caution when dealing with pointers as the previously incremented in this function points to the initial array that was pointed to. It required its pointer to pass to the function. Incrementing the internal pointer without due resource management might lead to errors (like past-end array access) after this.