int diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  
  if (0 < progress_len)
    {
      progress_len = 0;
      fputc ('\n', stderr);
    }

  va_start (ap, fmt);
  int result = verror (0, errnum, fmt, ap);
  va_end (ap);

  return result;
}