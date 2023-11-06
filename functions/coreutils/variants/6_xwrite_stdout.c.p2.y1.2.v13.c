1. Catching the error in a different manner:
In the code below instead of exiting with EXIT_FAILURE when fwrite() function fails, we print an error message and return from the function which changes the increment of the termination of the program.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void xwrite_stdout(char const* buffer, size_t n_bytes) 
{
    if(n_bytes != 0) 
    {
        size_t writ_size = fwrite(buffer, 1, n_bytes, stdout);
        if(writ_size < n_bytes) 
        {
            clearerr(stdout);
            fprintf(stderr, "Error writing standard output: %s\n", strerror(errno));
            return;
        }
    }
}


2. Simplifying conditions:
Flipping if conditions negation makes it more straightforward, removing unnecessary not-zero check and utilizing size_t nature of not being negative.


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

void xwrite_stdout(char const* buffer, size_t n_bytes) 
{
    if (!n_bytes) 
       return;

    if (fwrite (buffer, 1, n_bytes, stdout) == n_bytes) 
        return;
  
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}


3. Returning the result of write-validation immediately:
A cleaner way of realizing the verification of writing might be to return it right after checking > instead of enclosing inside the if condition.


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

void xwrite_stdout(char const* buffer, size_t n_bytes) 
{
    if(n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) == n_bytes)
        return;

    clearerr(stdout);
    error(EXIT_FAILURE, errno, "error writing %s", quoteaf ("standard output"));
}
