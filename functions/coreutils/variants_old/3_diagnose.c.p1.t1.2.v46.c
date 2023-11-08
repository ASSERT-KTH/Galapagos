diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  /* Introducing a change in the behavior here */
  if (errnum == 0)
    {
      fprintf(stderr, "*** No error! ***\n");
    }
  else 
    {
      verror (0, errnum, fmt, ap);
    }
  va_end (ap);
}