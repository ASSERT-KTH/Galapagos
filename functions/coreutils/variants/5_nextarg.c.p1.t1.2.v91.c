The function provided explicitly contains an error. It indicates "**args" however, 'args' is not defined in the function definition and only 'str' is referred to as its parameter. 

Anyway, this seems as if method checks whether 'str' parameter equals to first string in 'args' array. Accordingly nextarg should be defined to get the 'args' array as well. 

Here would be the enhanced function:

bool nextarg(char const *str, char **args)
{
    if (*args == nullptr){
        return false;
    } else {
        bool r = strcmp(*args, str) == 0; // STREQ seems like a call to string comparison with zero meaning they equals.
        if (r) *args += 1;                // we shouldn't add 'r' to args while 'r' is bool but can increment chars in args.
        return r;
    }
}
In the definition, we check whether 'str' parameter equals to first string in 'args' parameter and increment current pointer of 'args' if they match each other.

Please note, you may lead a memory leak unless correctly deallocating pointers.