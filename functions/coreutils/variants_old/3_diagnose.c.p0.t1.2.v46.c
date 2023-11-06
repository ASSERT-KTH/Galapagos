diagnose (int errnum, char const *fmt, ...)
{
  if (0 != progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  fflush(stderr);
  verror (0, errnum, fmt, ap);
  va_end (ap);
  fflush(stderr);
}