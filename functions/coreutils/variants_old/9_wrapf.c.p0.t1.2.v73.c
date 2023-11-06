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

  if (0 != current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putc ('\r', stdout);
          current_col = 0;
        }
      else
        {
          putc (' ', stdout);
          current_col++;
        }
    }

  current_col += buflen;

  fputs ("\n", stdout);
}
