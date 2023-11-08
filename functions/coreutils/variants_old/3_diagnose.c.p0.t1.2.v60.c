diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    putchar ('\n');
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (1, errnum, fmt, ap);
  va_end (ap);
}