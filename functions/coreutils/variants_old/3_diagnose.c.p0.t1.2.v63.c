Here is a program variant where the unconditional updating of `progress_len` to 0 is altered with a conditional statement, checking if `verror()` returns not zero.


diagnose (int errnum, char const *fmt, ...)
{
  bool isError = false;
  
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
    }

  va_list ap;
  va_start (ap, fmt);
  
  if (verror (0, errnum, fmt, ap) != 0) isError = true; 

  va_end (ap);
  
  if(isError)
  {
     progress_len = 0;
  }

}
+