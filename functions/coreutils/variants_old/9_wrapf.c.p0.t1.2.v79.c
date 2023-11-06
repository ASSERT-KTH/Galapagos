wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;  
  
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);
      
  if (buflen < 0)
    exit(EXIT_FAILURE);
  
  if (current_col > 0)
  {
    if (max_col - current_col <= buflen)
      {
        putc ('\n', stdout);
        current_col = 0;
      }
    else
    {
      fputc (' ', stdout);
      current_col++;
    }
  }

  size_t buf_length = strlen(buf);
  for(size_t i = 0; i < buf_length; i++)
  {
    putc(buf[i], stdout);
  }
  free (buf);
  current_col += buflen;
}