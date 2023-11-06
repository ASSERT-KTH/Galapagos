void diagnose (int errnum, char const *fmt, ...)
{
  if(progress_len > 0)
  {
     fprintf(stderr, "\n");
     progress_len = 0;
  } 

  va_list args;
  va_start(args, fmt);
  verror(0, errnum, fmt, args);
  va_end(args);
}