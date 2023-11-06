diagnose (int errnum, char const *fmt, ...)
{
  char newline = '\n';
  
  if (0 < progress_len)
    {
      fwrite (&newline, sizeof(newline), 1, stderr);
      progress_len = 0;
    }
  
  va_list ap;
  va_start (ap, fmt);

  if(errnum != 0)
    verror (0, errnum, fmt, ap);

  va_end (ap);
}