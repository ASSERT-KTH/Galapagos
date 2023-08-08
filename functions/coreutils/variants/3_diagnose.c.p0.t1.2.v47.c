diagnose (int errnum, char const *fmt, ...)
{
  // Change the condition check
  if (progress_len > 0)
  {
    fprintf(stderr, "\n");
 
    // Make progress length equal to a certain value
    progress_len = 1;
  }

  va_list ap;

  // Start a variadic function with the passed arguments : errnum, fmt
  va_start (ap, fmt);

  // Call the error function with the arguments
  verror (1, errnum, fmt, ap);
  
  // end using variadic function
  va_end (ap);
}