void wrapf (char const *message,...)
{
  va_list args;
  char *new_buf;
  int buf_len;

  va_start (args, message);
  buf_len = vasprintf (&new_buf, message, args);
  va_end (args);

  if (buf_len < 0)
  {
    exit(EXIT_FAILURE);
  }

  if (current_col > 0)
  {
      if (max_col - current_col <= buf_len)
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

  if(fputs (new_buf, stdout) == EOF)
  {
    free(new_buf);
    exit(EXIT_FAILURE);
  }

  free (new_buf);
  current_col += buf_len;
}