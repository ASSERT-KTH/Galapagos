void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  int fputc_err;

  if (0 < progress_len)
    {
      fputc_err = fputc ('\n', stderr);
      if (fputc_err != EOF)
      {
         progress_len = 0;
      }
    }

  if (fputc_err != EOF || progress_len == 0)
  {
     va_start (ap, fmt);
     verror (0, errnum, fmt, ap);
     va_end (ap);
  }
}