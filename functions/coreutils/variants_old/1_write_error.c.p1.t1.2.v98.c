Although the original function does not have any explicit return statement (void function essentially), the error function it eventually calls has an exit behavior that terminates the program.

If we want to maintain the core "error-reporting" functionality but change the function's behavior in terms of not terminating the program, rather we can manipulate errno directly and print a custom error message. Below is a variant program:


#include <stdio.h>
#include <errno.h>

void write_error (void)
{
    int saved_errno = errno;
    fflush(stdout);

    if(saved_errno != 0) 
    {
        clearerr(stdout);
        fprintf(stderr, "write error: %s\n", strerror(saved_errno));
        errno = 0; // subsequently, reset the errno
    }
}


In case of an error, this program will print the error message to the standard error stream and then reset the error value (errno). However, unlike the original program, it will not cause program termination.