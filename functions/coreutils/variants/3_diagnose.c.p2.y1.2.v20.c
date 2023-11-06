int diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  
  int result = verror(0, errnum, fmt, ap);
  
  va_end (ap);
  
  return result;
}