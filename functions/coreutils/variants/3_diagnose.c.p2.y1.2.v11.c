void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  
  if (progress_len > 0)
  {
    progress_len = 0;
    putc('\n', stderr);
  }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}