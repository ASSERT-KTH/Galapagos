void wrapf(const char *message, ...)
{
  va_list(args);
  char *buf;
  int bufsize;

  va_start(args, message);
  bufsize = vasprintf(&buf, message, args);
  va_end(args);

  if (bufsize < 0){
     xalloc_die();
  }

  else {
  
    if (0 < current_col) 
    {
      if ((max_col - current_col) <= bufsize)
      {
      printf("\n");
      current_col = 0;
      } 
      else 
      {
      printf(" ");
      current_col += 1;
      }
    }
  }

  fputs(buf, stdout);
  free(buf);
  current_col += bufsize;
}