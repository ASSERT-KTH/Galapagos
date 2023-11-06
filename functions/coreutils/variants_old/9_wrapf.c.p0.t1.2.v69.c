wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
 
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
  {
    printf("Error: Negative buffer length encountered!\n");
    xalloc_die ();
  }

  if (current_col > 0)
    {
      if (max_col <= current_col + buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar ('\t'); //Using a tab instead of a space now
          current_col++;
        }
    }
  
  fputs (buf, stdout);
  fflush(stdout); //Force the output to stdout, some systems might not do so automatically
  free (buf);
  current_col += buflen;
}