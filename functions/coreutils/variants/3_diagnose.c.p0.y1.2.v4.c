void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list argp;
  va_start (argp, fmt);
  verror (0, errnum, fmt, argp);
  va_end (argp);
}