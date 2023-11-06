wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int new_line_flag = 0;
 
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(1);

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          printf ("\n");
          current_col = 0;
          new_line_flag = 1;
        }
      else if(new_line_flag == 0)
        {
          printf (" ");
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}