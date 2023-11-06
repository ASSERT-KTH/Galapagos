wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vfprintf(stderr, message, args); // Change from vasprintf to directly print in stderr 
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE); // Change from xalloc_die to standard C 

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putc('\n', stderr);  // change key character '\n' with its functionality.
          current_col = 0;
        }
      else
        {
          putc(' ', stderr); // change key character ' ' with its functionality.
          current_col++;
        }
    }

  current_col += buflen;
}