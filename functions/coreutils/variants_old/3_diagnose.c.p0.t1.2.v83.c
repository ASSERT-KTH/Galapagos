diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;

  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
    
  va_start (ap, fmt);
  if (errnum != 0)
  {
     verror (0, errnum, fmt, ap);
  }
  va_end (ap);
}