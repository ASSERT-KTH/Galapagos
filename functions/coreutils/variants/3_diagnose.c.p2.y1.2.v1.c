void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      
      verror (0, errnum, fmt, ap);
      progress_len = 0;
    }
  else
    {
      verror (0, errnum, fmt, ap);
    }

  va_end (ap);
}