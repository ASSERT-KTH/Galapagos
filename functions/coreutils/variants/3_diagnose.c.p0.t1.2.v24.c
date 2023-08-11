diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fwrite ("\n", 1, 1, stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}