char const *wrapf (const char *message,...)
{
  va_list args_var;
  char *buffer;
  int length_buf;

  va_start (args_var, message);
  length_buf = vasprintf (&buffer, message, args_var);
  va_end (args_var);

  if (length_buf < 0)
    exit(EXIT_FAILURE);

  if (0 < current_col)
    {
      if (max_col - current_col <= length_buf)
        {
          printf ("%s", "\n");
          current_col = 0;
        }
      else
        {
          printf ("%s", " ");
          current_col++;
        }
    }

  fprintf (stdout, "%s", buffer);
  free (buffer);
  current_col += length_buf;
}