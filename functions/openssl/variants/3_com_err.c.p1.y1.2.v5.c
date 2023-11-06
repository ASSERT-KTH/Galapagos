1) Forward Declaration Transformation
This transformation merely involves moving the variable declaration of ap to the top of the function. Functionally, no change occurs with this transformation, but some C language standards such as C89 and older C++ standards prefer variable declarations at the top.


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
  
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}


2) Style Change / Bracing Convention Transformation
In this transformation, the C function keeps its original functionality, but the placement of the braces are changed. Placement of braces does not affect functionality, but presents different coding style conventions.


void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}


3) Expanding `va_start` and `va_end` macros
This transformation involves expanding out the `va_start` and `va_end` macros. Some programmers prefer to show explicitly how varargs are handled. Now with expanded code people without knowledge on va_list processing could understand more. Though, be aware that this solution will only work on certain architectures (and it will leak implementation details).


void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) {
   char *ap;
   ap=(char *)&fmt + ((sizeof(fmt)+sizeof(int)-1)/sizeof(int))*sizeof(int); // skip format argument in stack

   com_err_va(whoami, code, fmt, (va_list)ap);
     
   ap = (char*)0L; // "closing" the arguments list (va_end)
}


4) Removing Cruft Transform

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;
  
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
}

This fuction performs cancel each other out operations, so va_end always can be interpreted as redundant.

5) Iteration Via Casting
The `va_arg` function can be skipped through by use of type casting. With this method, the next parameter available can simply be incremented to directly, according to the size of the expected type. Example is only generally correct and targeted for educational purposes only, it should work as is correctly only on cppreference.


void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) {

    char *ap = &fmt + sizeof(fmt);

    com_err_va(whoami, code, fmt, *((va_list*)ap));
}
