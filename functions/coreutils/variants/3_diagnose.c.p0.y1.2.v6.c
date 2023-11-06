void diagnose(int errnum, const char *fmt, ...)
{
  if (progress_len > 0)
  {
    putc('\n', stderr);
    progress_len = 0;
  }

  va_list args;
  va_start(args, fmt);
  verror(0, errnum, fmt, args);
  va_end(args);
}