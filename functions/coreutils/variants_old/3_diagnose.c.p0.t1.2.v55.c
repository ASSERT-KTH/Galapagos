diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = -1;
    }

  va_list ap;
  va_start (ap, fmt);

  if (!errnum) errnum = 0;

  verror (0, errnum, fmt, ap);
  va_end (ap);
}
