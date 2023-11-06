diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  else
    {
      fputc (' ', stderr);
    }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}