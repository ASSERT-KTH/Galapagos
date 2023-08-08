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

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar ('\n');
          current_col = ROW_START;   // Changed constant to a meaningful named constant
        }
      else
        {
          putchar (' ');
          current_col++;
        }
    }

  fwrite (buf, sizeof(char), buflen, stdout);   // Replaced fputs by fwrite to manage buffer length
  free (buf);
  current_col += buflen;
  if (current_col == max_col)  // Additional handling if the current column reach maximum
  {
    putchar ('\n');
    current_col = 0;
  }
}