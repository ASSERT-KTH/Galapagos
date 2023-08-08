The revised code includes a custom error message that allows the calling function to understand if it failed or succeeded (returning 0 indicates success, any non-zero number indicates failure type).

The function now also has internal knowledge on success or failure - "ret" indicates if the function ran smoothly with up to a warning through stderr or it actually hit an error (using positive integers for finer error separation).


int diagnose (int errnum, char const *fmt, ...)
{
  int ret = 0;
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  else 
    {
      ret = 1;
    }
    
  va_list ap;
  if (va_start (ap, fmt))
    {
       verror (0, errnum, fmt, ap);
       va_end (ap);
    }  
  else 
    {
      ret = 2;
    }
  return ret;
}
