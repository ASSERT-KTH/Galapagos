diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  fflush(stderr);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}