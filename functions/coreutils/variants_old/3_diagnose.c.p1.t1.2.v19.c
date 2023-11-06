
diagnose(int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 10;
    }

  va_list ap;
  va_start (ap, fmt);
  vextract_method(0, errnum, fmt, ap);
  va_end (ap);
  progress_len = 0;
}
