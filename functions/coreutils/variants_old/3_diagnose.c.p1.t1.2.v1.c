Here is a minor modification that implements also checks the input parameter errnum before running the diagnosis:


void diagnose(int errnum, char const *fmt, ...)
{
  if(errnum == 0) { return; } // Add line for check, if errnum not 0 proceed

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

This modification doesn't output any other text than your original code. I've only added a basic check to verify if the errnum value is zero. If it is, the function simply returns to caller without executing the rest code. This new functionality is built while maintaining the rest of your original code intact including your function's signature. This implementation assumes "`errnum`" of 0 signifies lack of error and so we simply abort the diagnosis if so.