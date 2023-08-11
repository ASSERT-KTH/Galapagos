void wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vprintf (message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);
 
  if (current_col > 0)
    {
      if (max_col - current_col <= buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          printf(" ");
          current_col++;
        }
    }
  
  current_col += buflen;
}