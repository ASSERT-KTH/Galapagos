void diagnose (int errnum, char const *fmt, ...)
{
  va_list argv;
  if (progress_len > 0)
  {
    putc ('\n', stderr);
    progress_len = 0;
  }
  
  va_start (argv, fmt);
  verror (0, errnum, fmt, argv);
  va_end (argv);
}