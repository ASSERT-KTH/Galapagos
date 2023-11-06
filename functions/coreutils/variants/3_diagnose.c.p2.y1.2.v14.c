// Variant 1: Modify the if condition to be clearer
void diagnose(int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}

// Variant 2: Use ternary operator instead of if statement
void diagnose (int errnum, char const *fmt, ...)
{
  progress_len > 0 ? fputc ('\n', stderr) : 0;
  progress_len = 0;

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}
  
//Variant 3: Reset progress_len irrespective of its value.
void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
  }
  progress_len = 0;

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
}

// Variant 4: Use defined macro to clarify condition
#define PROGRESS_EXIST progress_len > 0
void diagnose (int errnum, char const *fmt, ...)
{
  if (PROGRESS_EXIST)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);
  verror(0, errnum, fmt, ap);
  va_end(ap);
} 

// Variant 5: Swap positions for error and zero in the verror function 
void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);
  verror(errnum, 0, fmt, ap);
  va_end(ap);
}