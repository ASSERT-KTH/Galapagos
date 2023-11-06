void diagnose (int errnum, char const *fmt, ...)
{
  va_list args_list;
  if (progress_len > 0)
  {
    putc ('\n', stderr);
    progress_len = 0;
  }

  va_start (args_list, fmt);
  verror (0, errnum, fmt, args_list);
  va_end (args_list);
}