Variant 1: Change the condition to check for progress_len:

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


Variant 2: Switch the code's order inside the "if" condition:

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    progress_len = 0;
    fputc ('\n', stderr);
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 3: Explicit initialization of va_list object:

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap = 0;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 4: Use of ternary operator to check progress_len condition:

diagnose (int errnum, char const *fmt, ...)
{
  progress_len > 0 ? (fputc ('\n', stderr), progress_len = 0) : 0;

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
