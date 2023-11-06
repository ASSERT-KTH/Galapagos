You can add custom error handling by introducing a new error code which, when equal to errnum, causes an error message not related to errnum but to personal diagnostic messages.


void diagnose (int errnum, char const *fmt, ...)
{
  if (errnum == 9999)
  {
    fprintf(stderr, "Custom error message\n");
    return;
  }
  
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}

This version of function checks if the error number is 9999 and then it treats this scenario as a special case by printing a specific error message, "Custom error message". Note that you can change this error message to any other you wish.