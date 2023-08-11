Sure, you can modify the function so that it checks whether or not error messages are displayed based on a certain flag or criteria. Here's an example, let me add a bool type variable "enableDiagnoseMatchingCriteria" that is true if the provided errnum matches with certain criteria (say, it should be negative in this case). If the criteria do not match then the function would simply return and no diagnostics message would get displayed.


diagnose (int errnum, char const *fmt, ...)
{
  bool enableDiagnoseMatchingCriteria = errnum < 0 ? true : false; 

  if (enableDiagnoseMatchingCriteria)
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


In the above code, if the "errnum" is non-negative, the function would return immediately. If it's negative, the function would operate exactly as before i.e., creating a newline if required and then hanldling the arguments using verror.