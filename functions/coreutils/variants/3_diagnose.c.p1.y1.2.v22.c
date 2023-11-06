1. Change let's simply sort the lines sequentially:

diagnose (int errnum, char const *fmt, ...)
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
}

2. Here is another variant of the code via condition inversion:

diagnose (int errnum, char const *fmt, ...)
{
  if ( !(progress_len < 0) )
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}

3. And yet another one by placing every statement in it's corresponding lines:

diagnose (int errnum, char const *fmt, ...)
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
}

4. Lastly, another variant with removed empty space from if block:

diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len) {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
