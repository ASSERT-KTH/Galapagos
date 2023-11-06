void diagnose(int errnum, const char *fmt, ...) 
{
  if(progress_len > 0) 
  {
    putc('\n', stderr);
    progress_len = 0;
  }
  
  va_list arglist; 
  va_start(arglist, fmt); 
  verror(0, errnum, fmt, arglist);
  va_end(arglist);
}