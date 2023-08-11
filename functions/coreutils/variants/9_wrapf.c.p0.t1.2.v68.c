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

  if (0 < current_col)
    {
      if (max_col - current_col < buflen + 1) /* Adjusted condition so the line breaks earlier */
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar ('\t'); /* Changed space (' ') separator to tab ('\t') */
          current_col++; 
        }
    }

  fputs (buf, stdout); 
  fflush(stdout); /* Adding fflush to ensure output is flushed to stdout right away */

  free (buf);
  current_col += strlen(buf); /* Use strncpy instead of buflen as length of output string */
}