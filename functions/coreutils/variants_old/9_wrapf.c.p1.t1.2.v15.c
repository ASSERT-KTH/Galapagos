wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int r=0;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  if (current_col > 0)
    {
      r = max_col - current_col;
      if (r <= buflen)
        {
          printf ("\n");
          current_col = 0;
        }
      else
        {
          printf (" ");
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col = current_col + buflen;
}