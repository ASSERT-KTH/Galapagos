For example, we can enhance the function to give a toggle option whether to display progressive marks on error messages or not.


diagnose (int errnum, char const *fmt, ...)
{
  static int showProgressIndicator = 1; 
  
  if (showProgressIndicator && 0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);

  // Handling a special error number (say -1) to toggle progressIndicator.
  if(errnum == -1)
    showProgressIndicator = !showProgressIndicator;
}

In the above modification to the original function, we've given a special meaning to an errnum of -1 . Whenever diagnose function is invoked with errnum as -1 we would toggle whether to show the progress marks before the error messages or not.