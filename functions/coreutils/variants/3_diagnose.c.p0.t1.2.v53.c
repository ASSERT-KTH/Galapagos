Here is a variant of the program:

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    progress_len = 0;
    fputc ('\n', stderr);
  }

  va_list ap;
  va_start(ap, fmt);
  
  verror (0, errnum == 0 ? 1 : errnum, fmt, ap); 
  
  va_end (ap);
}