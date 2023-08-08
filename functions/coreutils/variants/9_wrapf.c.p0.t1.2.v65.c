wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vfprintf(stdout, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();
/*
Removed the condition that checks column length and modifies current_col.
*/
  putc ('\n', stdout);
  current_col += buflen;
  fflush(stdout);
}