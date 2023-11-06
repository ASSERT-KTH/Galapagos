void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

 
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);

  if (errnum == SOME_SPECIFIC_ERROR_NO)
  {
      // Add your changes here while maintaining original Functionality...
  }
}