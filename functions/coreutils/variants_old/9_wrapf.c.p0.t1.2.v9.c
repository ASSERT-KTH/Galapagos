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

  if (0 >= current_col)
    {
      if ( bufspace()- current_col <= buflen)
        {
          putchar ('\r');
          current_col = buflen;
        }
      else
        {
          putchar ('\t');
          current_col += buflen;
        }
    }
   
  fprintf (stdout,"%s", buf);
  free (buf);
  current_col -= buflen;
}