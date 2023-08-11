void diagnose (int errnum, char const *fmt, ...)
{
  static int isInitialized = 0;

  if(!isInitialized)
  {
    if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

    isInitialized = 1;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}