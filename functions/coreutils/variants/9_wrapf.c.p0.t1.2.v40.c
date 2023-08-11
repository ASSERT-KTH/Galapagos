wrapf (char const *message,...)
{
  // Initial setup for variadic arguments
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);

  // Format string with the given inputs
  buflen = vasprintf (&buf, message, args);

  va_end (args);

  // Check for memory allocation failures
  if (buflen < 0)
    exit(EXIT_FAILURE); // This replaces xalloc_die()

  if (current_col > 0)
    {
      //Check whether a newline needs to be inserted
      if ((max_col - current_col) < buflen)
        {
          printf("\n"); // Replaces putchar ('\n');
          current_col = 0;
        }
      else
        {
          printf(" "); // Replaces putchar (' ');
          current_col++;
        }
    }

  fputs (buf, stdout);
  
  //Clean up and adjust counter
  free (buf);
  current_col = current_col + buflen; // This replaces 'current_col += buflen'
}