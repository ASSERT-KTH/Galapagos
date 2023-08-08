wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int temp_current_col = current_col;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    assert (0 && "memory allocation failure ");

  if (0 < temp_current_col)
    {
      if (max_col - temp_current_col <= buflen)
        {
          putchar ('\r');
          temp_current_col = 0;
        }
      else
        {
          putchar ('\t');
          temp_current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col = temp_current_col + buflen;
}