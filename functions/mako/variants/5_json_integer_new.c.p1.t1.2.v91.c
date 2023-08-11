You can use error handling to document if and when the allocation of memory fails. Although the returned value is the same as in the original function (NULL), more context is given about the error.

Here is a possible variant of the function:


#include <errno.h>
#include <stdio.h>

json_value * json_integer_new (json_int_t integer)
{
   errno = 0;
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (!value) {
       if (errno == ENOMEM) {
           fputs("Error: Unable to allocate memory.", stderr);
       }
       return NULL;
   }
   
   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}

By including `<errno.h>` and `<stdio.h>`, you equip the function with tools to handle memory allocation problems more informatively. If the allocation of memory fails (indicated by `value == NULL`), the function sets `errno` to `ENOMEM` (signifying "Not enough space") and writes "Error: Unable to allocate memory." to the stderr stream to report about the failure.

Maintaining the function's original functionality includes reporting about similar unhandled cases as earlier, such a value not being properly created. Therefore, useful additions to the code deal with the problem more descriptively, as in the above variant.

Use caution with error messages written to `stderr` (stderr can be redirected, redefined, blocked, or otherwise changed in its behaviour).