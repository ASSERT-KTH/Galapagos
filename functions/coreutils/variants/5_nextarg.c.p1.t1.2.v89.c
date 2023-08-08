The function as described doesn't seem to compile correctly. It uses an undeclared identifier, args, when it should be using str, the declared parameter. It does not appear to match the function signature. Below is an educated estimation of what your intended function could look like:

int nextarg(char const* str)
{
    if (str == nullptr)
        return 0;   // Return false if pointer is NULL
    else
    {
        // Assume STREQ is a Macro that performs string equality check
        int r = STREQ (str, "Sample String");
    
        if(r)
           str+= 1;
    
        return r;
    }
}

And here is how maintaining this functionality while changing its behavior a little:

int nextarg(char const* str)
{
   int r = (str != NULL) && STREQ (str, "Sample String");  
   
   if(r)
       str+= 1;
   
   return r;
}
