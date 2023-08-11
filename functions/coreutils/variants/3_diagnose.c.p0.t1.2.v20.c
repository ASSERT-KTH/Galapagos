diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    putchar ('\n');
    progress_len = 0;
  }
  
  va_list argptr;
  va_start (argptr, fmt);
  vfprintf (stderr, fmt, argptr);
  verror (0, errnum, fmt, argptr);
  va_end (argptr);
}