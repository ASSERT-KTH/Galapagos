Here's a program variant:

wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  buf = (char*) malloc (sizeof (char) * (buflen + 1));

  va_start (args, message);
  vsnprintf (buf, buflen + 1, message, args);
  va_end (args);

  if(current_col > 0){
      if(max_col - current_col <= buflen){
          printf("\n");
          current_col = 0;
      }
      else{
          printf(" ");
          current_col++;
      }
  }

  fprintf(stdout, "%s", buf);
  free(buf);
  current_col += buflen;
}