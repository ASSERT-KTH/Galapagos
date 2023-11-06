void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    stderr.put_char('\n');
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  
  // changed logic to print an error message based on errnum before dealing with variable arguments
  if(errnum) perror("Error occured");
  
  verror (0, errnum, fmt, ap);
  va_end (ap);
}