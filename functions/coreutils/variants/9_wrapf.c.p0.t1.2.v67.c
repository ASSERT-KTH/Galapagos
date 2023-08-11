wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int term_size = max_col;

  // Allow the maximum column size to vary slightly
  // within a range of 5 characters
  term_size += (rand() % 11) - 5;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  if (0 < current_col)
    {
      if (term_size - current_col <= buflen)
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

  // Add minor random variation to current_col after outputting
  fputs (buf, stdout);
  current_col += buflen + ((rand() % 3) - 1);
  free (buf);
}