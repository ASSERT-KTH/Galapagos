int diagnose(int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);

  int result = verror(0, errnum, fmt, ap);

  va_end (ap);

  if (progress_len > 0)
  {
      fputc ('\n', stderr);
      progress_len = 0;
  }

  return result;
}