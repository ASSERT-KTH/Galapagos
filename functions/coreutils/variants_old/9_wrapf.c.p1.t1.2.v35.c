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
          printf("\n");
          current_col = 0;
        }
      else
        {
          printf(" ");
          current_col++;
        }
    }

  fprintf(stdout, "%s", buf);
  free (buf);
  current_col += buflen;
}