wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(0, 0, message, args);
  buf = (char *) malloc((buflen+1) * sizeof(char));
  
  if (buf == NULL)
    xalloc_die ();
  
  va_end (args);

  va_start (args, message);
  vsnprintf(buf, (buflen + 1), message, args);
  va_end(args);

  if(0 < current_col)
    {
      if(max_col - current_col <= buflen)
        {
          printf("\n");
          current_col = 0;
        }
      else
        {
          printf(" ");
          current_col++;
        }
    }

  printf("%s", buf);
  free (buf);
  current_col += buflen;
}