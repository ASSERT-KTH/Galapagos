Here's a function variant with slightly varied behavior:


diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  if (errnum == 0) 
  {
    verror(0, errnum, "", ap);
  } 
  else 
  {
    verror (0, errnum, fmt, ap);
  }  
  va_end (ap);
}


In this function, when the error number is zero, an empty string is passed to the verror() function instead of the formatted string. Essentially, it suppresses the formatted message in the case of no error (errnum == 0), but executes as normally when an error exists.