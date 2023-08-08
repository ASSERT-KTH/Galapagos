diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0) // changing strict comparison to inequality, slight rephrasing of the condition
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  else 
    {
      fprintf(stderr, ""); // extra step: flushing stderr when no progress info has been outputted
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}