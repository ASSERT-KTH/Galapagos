1. Using fflush after fputc


diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    fflush(stderr); 
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


2. packing the stdout write into one line

diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len && fputc ('\n', stderr),progress_len = 0){}
  
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


3. Reversing if condition from implicit to explicit comparison with zero

diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
 

4. Deforestation (getting rid of helper variable ap)


diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
    
  verror (0, errnum, fmt, (va_start(va_list, fmt), va_list));
  va_end(va_list);
}
