The given program provides output to stderr of some error message. The transformation below modifies the behavior by sending output not only to stderr but also a log file.

Surely, the logs details are helpful in investigating errors that the function encounters. Note: In the following variant LOGFILE is assumed to be some GLOBAL variable or macro for file descriptor or file pointer of the log file, valid and writable, wherever logs needs to be captured.


#include <stdio.h>
void diagnose (int errnum, char const *fmt, ...)
{
    if (0 < progress_len)
    {
      fputc ('\n', stderr);
      fputc('\n', LOGFILE);
      progress_len = 0;
    }

    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);

    va_list ap_log;
    va_start(ap_log, fmt);
    verror(0, errnum, fmt, ap_log);
    va_end(ap_log);
}
