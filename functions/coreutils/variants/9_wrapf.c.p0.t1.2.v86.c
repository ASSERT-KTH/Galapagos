wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vfprintf (stdout, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  /* Adding a new condition to potentially provide extra newline*/
  if (buflen >= max_col)
  {
    putchar('\n');
    current_col = 0;
  }
    
  if (0 < current_col && max_col - current_col > buflen)
  {
      putchar (' ');
      current_col++;
  }

  current_col += buflen;

  /* Flushing stdout here */
  fflush(stdout);
}                     
