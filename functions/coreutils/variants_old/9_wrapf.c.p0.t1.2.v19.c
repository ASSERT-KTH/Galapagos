wrapf (char const *message, ...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    {
      /*This variant uses an exit call instead of xalloc_die to handle allocation failure*/
      //xalloc_die ();
      exit(1); // Signal abort to operating system
    }

  if (0 < current_col)
    {
      if (max_col - current_col < buflen)
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

  fseek(stdout, 0, SEEK_END); // Ensure writing begins at end-of-file
  fputs (buf, stdout);
  fflush(stdout); // Ensure output to stdout is delivered immediately

  free (buf);
  current_col = (current_col + buflen) % max_col; // consider the available column width to adjust current column before wrap around.
}