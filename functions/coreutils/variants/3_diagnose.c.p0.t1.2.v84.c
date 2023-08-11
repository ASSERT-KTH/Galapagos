diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len--;
    }

  va_list ap;
  va_start (ap, fmt);

  if(errnum != 0)
  {
    verror (0, errnum, fmt, ap);
  }
  else 
  {
    printf("Errnum is 0.\n");
  }

  va_end (ap);
}