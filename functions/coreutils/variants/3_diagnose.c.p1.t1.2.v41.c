void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  
  // Adding condition to determine errnum status and customizable message
  if(errnum < 0){
    verror (0, errnum, "NEGATIVE ERROR NUMBER: %s", ap);
  } else {
    verror (0, errnum, fmt, ap);
  }
  va_end (ap);
}