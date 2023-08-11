diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  
  if (errnum) 
  {
    verror (0, errnum, fmt, ap);
  }
  else
  {
    verror (0, errnum, "No error number provided", ap);
  }
  
  va_end (ap);
}