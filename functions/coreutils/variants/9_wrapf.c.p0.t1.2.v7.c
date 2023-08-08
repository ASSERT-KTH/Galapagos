wrapf(char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int needed_newline = 0;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);  // Instead of xalloc command, directly use exit command

  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
        {
          needed_newline = 1;
          current_col = 0;
        }
      else
        {
          putchar (' ');
          current_col += 2;
        }
    }

  if(needed_newline)
    putchar('\n');
  
  fwrite (buf, sizeof(char), buflen, stdout);
  free (buf);
  
  current_col += buflen;
}