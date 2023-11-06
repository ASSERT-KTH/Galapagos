void diagnose (int errnum, char const *fmt, ...)
{
  va_list arguments;
  if(progress_len > 0) 
  {
    fputs("\n", stderr);
    progress_len = 0;
  }

  va_start(arguments, fmt);
  verror(0, errnum, fmt, arguments);
  va_end(arguments);
}