void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  if (fmt[0] != '\0') {
    verror (0, errnum, fmt, ap);
  } else {
    verror (0, errnum, "No error message available.", ap);
  }
  va_end (ap);
}