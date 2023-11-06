void diagnose (int errnum, char const *fmt, ...)
{
  va_list args;
  if (progress_len > 0)
  {
    putc ('\n', stderr);
    progress_len = 0;
  }

  va_start(args, fmt);
  verror(0, errnum, fmt, args);
  va_end(args);
}