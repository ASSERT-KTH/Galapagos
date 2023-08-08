diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fprintf(stderr, "\n");
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  int error = errnum;
  verror (0, error, fmt, ap);
  va_end (ap);
}