wrapf (char const *message,...)
{
  va_list args;
  int buflen;
  char *buf = NULL;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
  {
    xalloc_die ();
  }
  else
  {
    if (current_col > 0)
    {
      int remaining_col = max_col - current_col;
      if (remaining_col <= buflen)
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

    int res = fputs (buf, stdout);
    if(res == EOF){
       xalloc_die ();
    }
    else {
      current_col = current_col + buflen;
    }
    free (buf);
  }
}