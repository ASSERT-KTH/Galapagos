diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc (' ', stderr); // change \n to space
      progress_len = 0;
    }
  else
    {
      fputc ('\n', stderr); // print newline when progress_len equals 0
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);

  fputc ('\n', stderr); // print a newline after every diagnose
}