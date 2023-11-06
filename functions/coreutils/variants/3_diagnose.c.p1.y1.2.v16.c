1. Swap `if` condition Values.

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0) {
   fputc ('\n', stderr);
   progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}

2. Use an inline `if` statement.

diagnose (int errnum, char const *fmt, ...)
{
  progress_len > 0 ? (fputc ('\n', stderr), progress_len = 0) : 0;

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}

3. Format conditional code on one line.

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0) { fputc ('\n', stderr); progress_len = 0; }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}

4. Use `do {} while (0)` after `va_end` macro.

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
  do {} while (0);
}
