void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;

  if (progress_len > 0)
  {
    putc ('\n', stderr);
    progress_len = 0;
  }

  va_start (ap, fmt);
  
  if(errnum != 0){
    verror (0, errnum, fmt, ap);
  } else {
    vfprintf(stderr, fmt, ap);
  }

  va_end (ap);
}