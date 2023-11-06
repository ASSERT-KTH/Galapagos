diagnose (int errnum, char const *fmt, ...)
{
  
  va_list ap;     
  va_start (ap, fmt); 

  if (0 < progress_len)
    {
      fputc ('\n', stderr);   
      progress_len = 0;
      fflush(stderr);  // flushes the output stream stderr
    }
  
  verror (0, errnum, fmt, ap); 
  va_end (ap); 

  fflush(stderr); // flushes the stderr stream again after processing va_end
}