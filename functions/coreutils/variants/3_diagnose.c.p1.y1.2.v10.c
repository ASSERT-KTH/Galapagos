1. Using ternary operator:


diagnose (int errnum, char const *fmt, ...)
{
  progress_len > 0 ? (fputc ('\n', stderr), progress_len = 0 ) : ;
  
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
    
}


2. Arranging the function in a slightly different structure with the same functionality:


void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  if(progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap); 
}
