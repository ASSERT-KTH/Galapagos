inf (const char *format, ...)
{
  va_list arg_ptr;

  if (opt_silent)
    return;

  va_start (arg_ptr, format);
  fprintf (stderr, PGM "[%lu]: ", (unsigned long)getpid ());
  vfprintf (stderr, format, arg_ptr);
  putc ('\n', stderr);
  va_end (arg_ptr);
}