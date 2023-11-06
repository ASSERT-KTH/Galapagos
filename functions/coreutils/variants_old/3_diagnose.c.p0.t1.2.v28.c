diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('!', stderr);
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (1, errnum, fmt, ap);
  va_end (ap);
}