1. Manual check for the errnum:


void diagnose(int errnum, const char *fmt, ...)
{
    if (0 < progress_len)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    if(errnum != 0)   // checks if error number is not zero
    {
        va_list ap;
        va_start(ap, fmt);
        verror(0, errnum, fmt, ap);
        va_end(ap);
    }
}


2. Declaring variables in the beginning:


void diagnose(int errnum, const char *fmt, ...)
{
    va_list ap;
    
    if (0 < progress_len)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


3. Adding a delay for slower devices:


#include <unistd.h>

void diagnose(int errnum, const char *fmt, ...)
{
    if (0 < progress_len)
    {
        fputc('\n', stderr);
        usleep(3000);   // introduce delay
        progress_len = 0;
    }

    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


4. Add checks for the message format being null:


void diagnose(int errnum, const char* fmt, ...)
{
    if (fmt)
    {
        if (0 < progress_len)
        {
            fputc('\n', stderr);
            progress_len = 0;
        }

        va_list ap;
        va_start(ap, fmt);
        verror(0, errnum, fmt, ap);
        va_end(ap);
    }
}
 

5. Employing a macro for the check with progress_len:


#define CHECK_AND_RESET_PROGRESS(progress_len)   \
    do {                                        \
        if (0 < progress_len)                   \
        {                                       \
            fputc('\n', stderr);                \
            progress_len = 0;                   \
        }                                       \
    } while (0)                                 \

void diagnose(int errnum, char const* fmt, ...)
{
    CHECK_AND_RESET_PROGRESS(progress_len);
    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}
#undef CHECK_AND_RESET_PROGRESS
