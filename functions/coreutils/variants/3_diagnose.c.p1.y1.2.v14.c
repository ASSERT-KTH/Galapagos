Variant 1:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if(0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 2:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 3:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  if(0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  va_end (ap);
}


Variant 4:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
  if(0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
}

Please note that some variants may change process order, and would not function identical to the original if side effects of the functions considerations are factored in.