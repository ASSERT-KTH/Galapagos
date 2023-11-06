wrapf (char const *message,...)
{
  va_list args;
  char *tmp_buf;
  int size;

  va_start (args, message);
  size = vasprintf (&tmp_buf, message, args);
  va_end (args);

  if (size < 0)
    exit(EXIT_FAILURE);

  if(current_col > 0 && max_col <= current_col + size)
    {
      putchar ('\n');
      current_col = 0;
    }

  fwrite (tmp_buf, size, 1, stdout);
  free (tmp_buf);
  current_col = current_col + size;
}