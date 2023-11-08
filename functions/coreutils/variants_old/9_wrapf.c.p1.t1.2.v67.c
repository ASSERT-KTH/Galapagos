wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0){
    xalloc_die ();
  }

  if (current_col > 0){
      if ((max_col - current_col - 1) < buflen){
          putchar ('\n');
          current_col = 0;
      } 
  }
  else{
      putchar (' ');
      current_col++;
  }
  
  int bytesWritten = fputs(buf, stdout);
  if(bytesWritten != buflen) {
      xalloc_die (); 
  }

  free (buf);
  current_col += buflen;
}