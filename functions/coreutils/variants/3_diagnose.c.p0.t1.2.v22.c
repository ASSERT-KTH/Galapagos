diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len != 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  fflush(stderr);      // additional line to flush current buffered data in 'stderr', thus immediately letting error appear. 
  va_end (ap);
}