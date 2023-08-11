void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  // if errnum is zero, print the formatted message as is
  if (errnum == 0) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
  } else {
    va_list ap;
    va_start (ap, fmt);
    verror (0, errnum, fmt, ap);
    va_end (ap);
  } 
}