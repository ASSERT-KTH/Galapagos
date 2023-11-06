wrapf (char const *message,...)
{
  va_list args;
  char *buffer;
  int buffer_len,isPrinted=0;

  va_start (args, message);
  buffer_len = vsprintf (&buffer, message, args);
  va_end (args);

  if (buffer_len < 0)
    xalloc_die ();

  if (current_col > 0)
    {
      if (max_col - current_col < buffer_len)
        {
          printf ("\n");
          current_col = 0;
        }
      else if (max_col - current_col >= buffer_len)
        {
          printf (" ");
          isPrinted = 1;
        }
    }

  fputs (buffer, stdout);
  if(isPrinted == 1)
     current_col++;
  free (buffer);
  current_col += buffer_len;
}