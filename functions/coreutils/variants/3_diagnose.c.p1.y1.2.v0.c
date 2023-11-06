1. Switching the argument order in `va_start` call


void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, errnum);
  verror (0, fmt, ap, errnum);
  va_end (ap);
}


2. Using fprintf instead of fputc


void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fprintf(stderr, "\n");
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


3. Changing the order of conditional check 


void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


4. Combining conditions with && OPERATOR


void diagnose (int errnum, char const *fmt, ...)
{
  if (!(progress_len <= 0))
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Note: This answer has been edited to delete the same duplicated portion of the content.

5. Resolving putchar() call entirely.


void diagnose (int errnum, char const *fmt, ...)
{
  if (0 != progress_len)
    {
      putc(*"\n", stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
