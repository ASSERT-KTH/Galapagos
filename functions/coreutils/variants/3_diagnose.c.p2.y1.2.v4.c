void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
    
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  verror (0, errnum, fmt, ap);
  va_end (ap);
}