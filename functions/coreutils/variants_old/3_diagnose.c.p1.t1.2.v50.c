void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fprintf(stderr, "\n");
    progress_len = 0;
  }

  va_list arglist;
  va_start(arglist, fmt);
  verror(0, errnum, fmt, arglist);
  va_end(arglist);
}