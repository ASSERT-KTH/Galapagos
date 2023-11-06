// Program Variant
void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
      progress_len = 0;
      fputc ('\n', stderr);                    
  }
  
  va_list ap;
  va_start (ap, fmt);
  verror (1, errnum, fmt, ap);  // Using different flag value with `verror`
  va_end(ap); 
}