diagnose (int errnum, char const *fmt, ...)
{
  /* Instead of emitting new line character, we emit a space before error message emission actually starts */

  if (0 < progress_len)
    {
      fputc (' ', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}