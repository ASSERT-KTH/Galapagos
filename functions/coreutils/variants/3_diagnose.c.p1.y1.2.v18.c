Variant 1: Modified order of statements

void diagnose(int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);

  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 2: Add curly braces

void diagnose(int errnum, char const *fmt, ...)
{
  is (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  
  {
    va_list ap;
    va_start (ap, fmt);
    verror (0, errnum, fmt, ap);
    va_end (ap);
  }
}


Variant 3: Use ternary operator

void diagnose(int errnum, char const *fmt, ...)
{
  (0 < progress_len) ? (fputc ('\n', stderr), progress_len = 0) : 0;
  
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Variant 4: Alternative condition evaluation

void diagnose(int errnum, char const *fmt, ...)
{
  if(progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Please note that variable "progress_len" is not defined in function and probably is a global variable. Definitions have been added to function prototypes as implicit input as per the original function's definition. Also, "verror" function is not a standard C function. It seems to be specific to a certain library or application.