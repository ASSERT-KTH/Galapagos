wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen == -1)
    xalloc_die ();

  if (current_col > 0)
    {
      if ((max_col - current_col) < buflen)
        {
          printf("\n");
          current_col = 0;
        }
      else
        {
          fwrite(" ", sizeof(char), 1, stdout);
          current_col++;
        }
    }

  fwrite (buf, sizeof(char), buflen, stdout);
  free (buf);
  current_col += buflen;
}