Here's a program variant:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  else
    {
      fputc ('\n', stdout); // write to stdout in case no progress has been made.
    }

  verror (0, errnum, fmt, ap);
  va_end (ap);
}