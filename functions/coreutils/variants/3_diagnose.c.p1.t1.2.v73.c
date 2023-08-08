Here's a similar function which changes behaviour i.e., it will now check if the error number is less than zero, then only diagnosing the error, whereas the previous implementation diagnosed the error always regardless of error number:


void diagnose (int errnum, char const *fmt, ...)
{
  if (errnum < 0)
  {
    if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

    va_list ap;
    va_start (ap, fmt);
    verror (0, errnum, fmt, ap);
    va_end (ap);
  }
}


Just like the original, this function maintains the behaviour of formatting the varied work dealing with an unknown number of parameters (`va_list ap, va_start(), va_end()`) and the use of putc() to work with file pointers. Crucially this function still deals with error numbers and retains the original's signature. However, it now only diagnoses errors if their number is less than zero instead of all.