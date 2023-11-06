char *nextarg(char const *str)
{
    bool r;
    
    if (args == NULL)
        return false;
        
    r = STREQ(args, str);
 
    if (r)
      args++;

    return r;
}
There may appear to be minor changes in the look, but both versions provide the same functionality—comparing the 'args' string with the 'str' string provided to the function, making use of STREQ to check if they're the same. If they're the same, the pointer 'args' will move/imcrement by the value of r (1 if strings are equal and 0 otherwise). It will and then return the result of the strings' comparison.