Variant 1:

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 2:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;

  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len -= progress_len;
    }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap); 
  va_end (ap);
}


Variant 3:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  verror (0, errnum, fmt, ap);
  va_end (ap);
}
