Variant 1:

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    putchar('\n');
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
  progress_len = (progress_len>0) ? (fputc('\n', stderr), 0) : progress_len;

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 3:

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fprintf(stderr, "\n");
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
 

Variant 4:

diagnose (int errnum, char const *fmt, ...)
{
  fputc ((progress_len>0)?'\n':'\0', stderr);
  progress_len = (progress_len>0) ? 0 : progress_len;

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
