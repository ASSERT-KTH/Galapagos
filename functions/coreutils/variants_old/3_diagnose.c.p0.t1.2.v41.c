diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc (' ', stderr); 
      fputc ('\n', stderr); // adding space before '\n'
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  if(errnum == 0) { // if errnum is 0, it acts exactly like verorr
      verrror(fmt, ap);
  } else {
      verror (0, errnum, fmt, ap);
  }
  va_end (ap);
}