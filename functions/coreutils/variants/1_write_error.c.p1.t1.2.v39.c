The function `write_error()` logs an error message related to system failures encountered while writing to data streams. Suppose we want to add an extra functionality of logging the error message to a file, the revised function could be as shown below.

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>

void write_error (void)
{
    FILE *fd = fopen("log.txt", "a");
    int saved_errno = errno;
    fflush (stdout);
    clearerr (stdout);
    if (fd != NULL)
    {
        error_at_line(EXIT_FAILURE, saved_errno, "log.txt", 0, "write error");
        fclose(fd);
    }
    else
    {
        error (EXIT_FAILURE, saved_errno, "write error");
    }
}

The revision maintains the original functionality but includes additional functionality. It first attempts to open a file, "log.txt," under append mode. If the file is successfully opened, it attempts to append the error message in it, after which it closes the file before returning. In case the file is unsuccessfully opened, it proceeds with the original implementation.