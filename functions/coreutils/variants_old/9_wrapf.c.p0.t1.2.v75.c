wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int col_space;

  va_start (args, message);
  buflen = vsprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  col_space = max_col - current_col;

  if (0 < current_col)
    {
      if (col_space <= buflen)
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

  printf ("%s", buf);
  free (buf);
  current_col = current_col + buflen;
}