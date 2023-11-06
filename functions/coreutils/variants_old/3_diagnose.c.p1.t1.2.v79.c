/**
 * Program variant that changes the behavior of the original function 
 * while maintaining its original functionality. In this version, the 
 * function first checks if stderr is available before trying to write to it.
 * If stderr is not available, it writes to stdout instead.
 **/
void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
  {
    if (stderr != NULL)
      fputc ('\n', stderr);
    else 
      fputc ('\n', stdout);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);

  if (stderr != NULL)
    verror (0, errnum, fmt, ap);
  else 
    vfprintf (stdout, fmt, ap);   // changed this to vfprintf because there's no stdout equivalent for verror

  va_end (ap);
}