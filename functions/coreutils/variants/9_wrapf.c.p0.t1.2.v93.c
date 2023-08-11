wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int termwidth = 80; // Assuming a terminal width of 80 characters, adjust as needed.

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE); // Using the standard way to terminate if an error occurs.

  if (0 < current_col)
    {
      if (max_col - current_col < buflen)
        {
          if (buflen > termwidth)
            buddlen = termwidth; // Wrapping long output to available terminal width.

          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar (' ');
          current_col++;
        }
    }

  fwrite (buf, sizeof(char), buflen, stdout); // Using fwrite instead of fputs.
  free (buf);
  current_col += buflen;
  
  if (current_col > max_col) // Resetting current_col if it exceeds max_col
    current_col = 0;
}