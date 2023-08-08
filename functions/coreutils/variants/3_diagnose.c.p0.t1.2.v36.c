This diagnose function is a variant that changes the condition used for outputting a newline character to stderr. It also includes error handling after calling the verror function.


void diagnose(int errnum, char const *fmt, ...)
{
  if (progress_len != 0)
  {
    if (fputc ('\n', stderr) == EOF)
    {
      // Handle output error here
    }
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  if (verror(0, errnum, fmt, ap) == -1)
  {
    // Handle error calling verror here
  }
  va_end (ap);
}

This diary function is designed to suppress the newline output if progress_len is equal to zero.


void diagnose(int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
  {
    fputc('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);

  if (verror(0, errnum, fmt, ap) != 0)
  {
    fputc('\n', stderr);
  }
  
  va_end (ap);
}
