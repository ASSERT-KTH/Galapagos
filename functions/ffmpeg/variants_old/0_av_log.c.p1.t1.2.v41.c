You can keep the function's original functionality while adding extra behavior by inserting code that performs additional operations before or after the call to the original behavior. For example, you could add logging code that prints out the function's parameters each time it's called.

In the example below, the behavior of the function is changed by adding printf statements to log the function calls, but functionality is preserved because the remainder of the function's code is unchanged:


#include <stdarg.h>
#include <stdio.h>

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    // Extra behavior: Print out the function's parameters
    printf("av_log called with avcl: %p level: %d fmt: %s\n", avcl, level, fmt);

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);

    // Extra behavior: indicate that the function has finished executing
    printf("av_log function has executed\n");
}

Remember to include the implementation or header file that contains the declaration of `av_vlog`. Extra caution should also be taken when logging variable-argument functions such as printf. Fmt might contain sensitive user data that you would not wish to log, especially if this function is part of a library that can be used by 3rd party application. Support might be needed from the owner or knowledge on the string that this log function is supposed to print. In many cases, fmt within log functions do not contain user data. It formats the log message grammar but sensitive user/the output might exist within the variable-argument part accessed by va argument methods.