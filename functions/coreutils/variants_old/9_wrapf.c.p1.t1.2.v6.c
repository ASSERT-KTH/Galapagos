The program variant would replace putchar with printf for better readability and efficiency.


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE); 

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

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}

This variant uses printf instead additionally, error checking has been improved-using exit() instead of xalloc_die(). This provides a more standard error handling response if buflen < 0.