wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (0, 0, message, args);
  buf = (char*) malloc(buflen + 1);
  vsnprintf (buf, buflen+1, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (1 <= current_col)
    {
      if ((max_col - current_col) < buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar (' ');
          current_col += 1;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col = current_col + buflen;
}