First Variant:


void diagnose (int errnum, char const *fmt, ...) 
{
  va_list ap;
  
  if (0 < progress_len) 
  {
  putc ('\n', stderr);
  progress_len = 0;
  }
  
  va_start (ap, fmt);
  vfprintf (stderr, 0, errnum, fmt, ap);
  va_end (ap); 
}


Second Variant:

void diagnose (int errnum, char const *fmt, ...) 
{
  va_list ap;

  progress_len > 0 ? (putc ('\n', stderr), progress_len = 0) : 0;
  
  va_start (ap, fmt);
  vfprintf (stderr, 0, errnum, fmt, ap);
  va_end (ap);
}


Third Variant:


void diagnose (int errnum, char const *fmt, ...) 
{
  va_list printer;
  
  (progress_len > 0) && (putc('\n', stderr), progress_len = 0); 
  
  va_start (printer, fmt);
  vfprintf (stderr, 0, errnum, fmt, printer);
  va_end (printer);
}

Please note that `verror` and `va_start` are Directives specific to C and in some variant, they might be different or may not work if the compiler do not recognized them. However, unless you mention explicitly, it is assumed that your implementation trusts these directives.