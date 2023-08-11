Here's a slight variation of the original function that uses fputs instead of fputc and adds a fflush call to ensure immediate output. 

diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputs ("\n", stderr);
      fflush(stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}