Variant 1: 

void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if (0 < progress_len)
    {
      prog_char =progress[0];
      fprintf(stderr, "\n");
      progress_len = 0;
    }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 2: 

void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      fflush(stderr);
      progress_len = 0;
    }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 3: 

void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if (0 < progress_len)
    {
      putc ('\n', stderr);
      progress_len = 0;
    }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
