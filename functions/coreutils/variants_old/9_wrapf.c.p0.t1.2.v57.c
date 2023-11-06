wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int printed_char;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          printed_char = putchar ('\n');
          current_col = (printed_char != EOF) ? 0 : current_col;
        }
      else
        {
          printed_char = putchar (' ');
          current_col = (printed_char != EOF) ? current_col + 1 : current_col;
        }
    }

  printed_char = fputs (buf, stdout);
  free (buf);
  current_col += (printed_char != EOF) ? buflen : 0;
}