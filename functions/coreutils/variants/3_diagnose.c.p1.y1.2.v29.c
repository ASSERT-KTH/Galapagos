1. Inline Code Transformation

The inline code transformation allows you to make the function body directly insertable or usable wherever that function is called by specifying 'inline' at the beginning of the function.


inline void diagnose (int errnum, char const *fmt, ...)
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


2. Structuring (Removing Else):


void diagnose (int errnum, char const *fmt, ...)
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


3. Call by Reference
Here the pointer will be sent when it calls the value in the function. 


void diagnose (int *errnum, char const *fmt, ...)
{  
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, *errnum, fmt, ap);
  va_end (ap);
}


Changes in function signature comes out to be challenging considering the function in question does not return any value (is void) and uses an ellipsis (va_list) to accept a list of arguments. As mentioned in the guidelines, maintaining the original function's signature prohibits us to do many transformation such as using pointers for the values or changing the parameters.