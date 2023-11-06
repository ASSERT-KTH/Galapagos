Variant 1:

diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if(progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}


Variant 2:

diagnose (int errnum, char const *fmt, ...)
{
  if(progress_len > 0)
  {
    progress_len = 0;
    fputc ('\n', stderr);
  }

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}


Variant 3:

diagnose (int errnum, char const *fmt, ...)
{
  if(0 != progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}


Variant 4:

diagnose (int errnum, char const *fmt, ...)
{
  if(0 < progress_len)
  {
    progress_len = 0;
    fputc ('\n', stderr);
  }

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}


Variant 5:

diagnose (int errnum, char const *fmt, ...)
{
  if(0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list argList;
  va_start(argList, fmt);
  verror(0, errnum, fmt, argList);
  va_end(argList);
}
