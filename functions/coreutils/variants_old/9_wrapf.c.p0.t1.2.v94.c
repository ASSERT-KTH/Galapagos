wrapf(char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(1); // Instead of calling a function (xalloc_die) to terminate program, use exit directly.

  if (current_col > 0) // Instead of checking if current_col is greater than zero, check if its simply not zero.
  {
    if (max_col - current_col <= buflen)
    {
      putc('\n', stdout); // Instead of using putchar, use putc and explicitly identify stdout as destination.
      current_col = 0;
    }
    else
    {
      putc(' ', stdout); // Same as above
      ++current_col ; // Pre-increment the current_col
    }
  }

  fprintf(stdout, "%s", buf); // Instead of fputs, use fprintf to explicitly specify the formatting.
  free (buf);
  current_col += buflen ;
}