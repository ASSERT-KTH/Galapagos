void diagnose(int errnum, const char* fmt, ...)
{
  if (progress_len > 0)
  {
    fprintf(stderr, "\n");
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}