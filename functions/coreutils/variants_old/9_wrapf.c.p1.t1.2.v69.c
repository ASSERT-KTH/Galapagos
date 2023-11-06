The variant program would look as follows:


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen, space_width = 0;
  
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end(args);

  if (buflen < 0)
    xalloc_die ();

  char *new_buf = malloc(buflen + 1);

  if(0 < current_col)
  {
      for(int i = 0; buf[i]; i++){
          if(buf[i] == ' '){
            space_width++;
            continue;
          }
          new_buf[i-space_width] = buf[i];
      }
      buflen -= space_width;
      
      if (max_col - current_col <= buflen)
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

  fputs (new_buf, stdout);
  
  free(buf);
  free(new_buf);
  
  current_col += buflen;
}


The new functionality of the revised program is that it eliminates all the contained spaces in initial buffer. The resulting output is streamlined compared to before. It prints out based on each newline or space along the columns. The space is introduced either when the calculated `current_col` doesn't have enough space left for the current bunch of reserved spaces in `buf`, or no space is required when there are spaces in the `buf` for filling the remaining columns in `current_col`. This is represented by leveraging the variable `space_width` to remove all spaces.