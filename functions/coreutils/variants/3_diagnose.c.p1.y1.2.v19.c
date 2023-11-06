1. Re-arranging the lines of the code:


diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


2. Merging the lines with va_start and va_end, and replacing verror with its definition:

Variables `errnum` and `ap` put the end of verror needing:

#define verror(status, errnum, format, ap) 0,__format,__va_alist,__format
diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap), va_end (ap);
}

3. Converting if condition from anything with positive `progress_len` (Greater-Than Operator "<") to `progress_len` is not equal to zero (!(Equality Operator)):


diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  
  if (progress_len != 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
