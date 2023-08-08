Sure, I can provide a slightly modified version of the function with the same functionality.


nextarg (char const *str)
{
    bool r = false;

    if (*args != nullptr) 
    {
        r = STREQ (*args, str);
        if (r) 
        { 
         args++; 
        }
    }
   
   return r;
}
 

Only include this portion if you want updated function according to C99 standard.


#include <string.h> //for 'strcmp' function

int nextarg(const char *str, char **args)
{
    // operation '==' has logical instead of physical meaning
    if (strcmp(*args, str) == 0)
    {
        //Move to the next character. Note: here '1' is equal to 'sizeof(char)'
        *args += 1;
        return 1;
    }
    return 0;
}

Be sure to call the function like this:


int res = nextarg("something", &args);
