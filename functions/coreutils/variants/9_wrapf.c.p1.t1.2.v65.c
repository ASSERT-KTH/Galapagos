wrapf (char const *message,...)
{
  va_list args;
  char *new_buf;
  int new_buflen;

  va_start (args, message);
  new_buflen = vasprintf (&new_buf, message, args);
  va_end (args);

  if (new_buflen < 0)
    xalloc_die ();

  if (current_col > 0)
    {
      if ((max_col - current_col) <= new_buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar (' ');
          current_col++;
        }
    }

  fputs (new_buf, stdout);
  free (new_buf);
  current_col += new_buflen;
}