wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  int threshold = max_col - current_col;
  if (current_col > 0)
    {
      if (threshold <= buflen)
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

  int write_result = fputs (buf, stdout);
  if (write_result < 0)
  {
      free(buf);
      xalloc_die ();
  }
  
  free (buf);
  current_col += buflen;
}