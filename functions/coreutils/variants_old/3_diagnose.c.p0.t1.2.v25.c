diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      progress_len = 0;
      fputc ('\n', stderr);
    }

  va_list ap;
  va_start (ap, fmt);
  if (errnum != 0) 
  {
    verror (0, errnum, fmt, ap);
  }
  va_end (ap);
}