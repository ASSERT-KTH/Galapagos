
void diagnose (int errnum, char const *fmt, ...)
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


void diagnose (int errnum, char const *fmt, ...)
{
  if (! (progress_len <= 0))
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if (0 < progress_len)
    {
      (void)fputc ('\n', stderr), progress_len = 0;
    }

  va_start (ap, fmt), verror (0, errnum, fmt, ap);
  va_end (ap);
}


void diagnose (int errnum, char const *fmt, ...)
{
  enum {
    result = fwrite("\n", sizeof(char), 1, stderr);
    result_len = (int)sizeof(result) > progress_len;
  };

  if (result_len && progress_len > 0) {
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
