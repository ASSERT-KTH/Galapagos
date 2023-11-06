diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;

  if (0 < progress_len)
    {
      fputc (' ', stderr);
      fputc ('\n', stderr);
      progress_len = 0;
    }
    
  va_start (ap, fmt);

  verror (0, errnum, fmt, ap);
  if (errnum) fputc ('\n', stderr);

  va_end (ap);
}