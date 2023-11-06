
diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;

  // Wrap the calls to va_start and va_end in a conditional that
  // checks whether fmt is not NULL, a possible error condition 
  // the original implementation did not care about.
  if (fmt != NULL)
    {
      va_start (ap, fmt);
      verror (0, errnum, fmt, ap);
      va_end (ap);
    }
  else
    {
      fprintf(stderr, "Received null pointer when expecting format string.");
    }
}
