diagnose (int errnum, char const *fmt, ...)
{
  if (0 != progress_len)
  {
    fputc ('\n', stderr);
    fflush(stderr);
    progress_len = 0;
  }
  
  va_list args;
  va_start (args, fmt);
  verror (0, errnum, fmt, args);
  va_end (args);
}