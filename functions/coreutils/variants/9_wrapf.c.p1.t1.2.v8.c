Here's a slight variant of the given function. We preserve everything about the main function in terms of its functionality and its characteristic. We then re-order some parts purely in favour of readability, store the length of the message firstly and decide based on that whether or not a space or a newline is needed:


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();
  
  current_col += buflen;
  if (current_col > 0)
  {
    if (max_col <= current_col)
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

  fputs (buf, stdout);
  free (buf);
}

We moved `current_col += buflen;` up before deciding on which pady character to add. This way we can base our decision more directly on `current_col`.