void diagnose(int errorCode, const char *descriptor, ...)
{
  if (progress_len > 0)
  {
    fprintf(stderr, "\n");
    progress_len = 0;
  }

  va_list valist;
  va_start(valist, descriptor);
  verror(0, errorCode, descriptor, valist);
  va_end(valist);
}