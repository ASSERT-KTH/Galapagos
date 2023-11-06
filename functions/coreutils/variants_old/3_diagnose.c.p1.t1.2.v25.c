diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  // Code intended to maintain original functionality 
  
  else verror (0, errnum, fmt, ap);  
  
  va_end (ap);
}