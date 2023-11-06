void wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int space_needed = 0;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit (EXIT_FAILURE);
  
  space_needed = 0 < current_col ? (max_col - current_col <= buflen): 0;
  
  if (space_needed)
    {
      putchar ('\n');
      current_col = 0;
    }
  else if(current_col > 0)
    {
      putchar (' ');
      current_col++;
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}