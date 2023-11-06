void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
      putc ('\n', stderr);
      progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
Please note that putc is equivalent to fputc, therefore, the functionality is retained.