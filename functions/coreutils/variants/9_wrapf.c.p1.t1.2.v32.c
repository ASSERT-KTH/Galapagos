Your request indicates that the desired new function should fundamentally behave the same as the original, with the same functionality. However, it should feature some changes to its code as to suggest that there is variation in the overall coding approach. Below represents one such variant.


wrapf (char const *message,...)
{
  va_list args;
  char *buffer;
  int bufferLength;

  va_start (args, message);
  bufferLength = vasprintf (&buffer, message, args);
  va_end (args);

  if (bufferLength < 0)
    xalloc_die ();

  if (current_col > 0)
    {
      if ((max_col - current_col) <= bufferLength)
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

  fwrite (buffer, sizeof(char), bufferLength, stdout);
  free (buffer);
  current_col += bufferLength;
}

It takes in any number of arguments of any data type. It interprets them according to a format string and writes them to the buffer `buffer` according to that format string. Please note `printf() family doesn't explicitly deal with mechanisms needed to handle variable argument list, core task is still being performed by the "v" variants. ;)