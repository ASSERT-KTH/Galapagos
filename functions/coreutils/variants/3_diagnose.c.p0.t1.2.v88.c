Consider this variation of your provided function: 


diagnose (int errnum, char const *fmt, ...)
{
  if (0 <= progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  if (errnum >= 0) {
    verror (1, errnum, fmt, ap);
  } else {
    verror (0, errnum, fmt, ap);
  }
  va_end (ap);
}


Modifications I made here:

1. I've modified the condition to if (0 <= progress_len) instead of if (0 < progress_len). This will cause the program to behave slightly differently when progress_len is equal to zero.

2. I've added a new condition that checks errnum before passing it to verror. This adds ability to modify whether the function uses the verbose flag for verror, in circumstances where errnum is not a positive number. However original functionality when incoming error numbers are positive, remains same.