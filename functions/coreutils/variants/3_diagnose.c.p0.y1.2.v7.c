void diagnose (int errnum, char const *fmt, ...)
{
  if (progress_len > 0)
    {
      putc ('\n', stderr);
      progress_len = 0;
    }
    
  va_list args_pointer;
  va_start(args_pointer, fmt);

  verror(0, errnum, fmt, args_pointer);

  va_end(args_pointer);
}