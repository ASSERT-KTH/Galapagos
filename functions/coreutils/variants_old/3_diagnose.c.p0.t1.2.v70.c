Here's a variation of the code that lightly changes its behavior, by putting a condition to the fputc function and the update of progress_len variable.

diagnose (int errnum, char const *fmt, ...)
{
  int verbosity = 1;
  if (verbosity && 0 < progress_len)
  {
      fputc ('\n', stderr);
      progress_len = verbosity * 0;
  }

  va_list ap;
  va_start (ap, fmt);
  if (verbosity)
    verror (verbosity, errnum, fmt, ap);
  else
    verror (0, errnum, fmt, ap);
  va_end (ap);
}
In this variation, also it has added another condition to the verror function through an verbosity int variable. The same verbosity variable has used to expand the program with more features while preserving its original functionality.