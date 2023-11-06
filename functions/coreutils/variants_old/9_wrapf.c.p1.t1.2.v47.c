wrapf (char const *message,...)
{
  va_list args;
  int buflen;

  va_start (args, message);
  char *buf = NULL;

  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
  {
    if (buf != NULL)
    {
      free(buf);
    }
    xalloc_die ();
  }

  if (current_col > 0)
  {
    if (current_col + buflen >= max_col)
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

  fprintf(stdout, "%s", buf);
  current_col += buflen;

  if (buf != NULL)
  {
    free(buf);
    buf = NULL;
  }
}