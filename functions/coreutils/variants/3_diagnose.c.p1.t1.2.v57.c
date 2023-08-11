void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  if (0 < progress_len)
    {
      int tmp = fputc ('\n', stderr);
      (void)tmp;  // Supress warnings about not checking return value of fputc
      progress_len = 0;
    }

  verror (0, errnum, fmt, ap);
  va_end (ap);
}