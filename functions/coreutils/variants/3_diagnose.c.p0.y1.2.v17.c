void diagnose (int errnum, char const *fmt, ...) 
{
  va_list arg_list;
  if (progress_len > 0) 
  {
    putc ('\n', stderr);
    progress_len = 0;
  }
  
  va_start (arg_list, fmt);
  verror (0, errnum, fmt, arg_list);
  va_end (arg_list);
}