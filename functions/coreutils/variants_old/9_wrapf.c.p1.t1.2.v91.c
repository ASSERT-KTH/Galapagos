
wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(NULL, 0, message, args) + 1; 
  buf = malloc(buflen);

  if(buf == NULL)
    xalloc_die ();

  vsprintf(buf, message, args);      
  va_end (args);      

  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
        {
          putc('\n', stdout); 
          current_col = 0;
        }
      else
        {
          putc(' ', stdout);
          current_col++;
        }
      fflush(stdout); 
    }
    
  fwrite(buf, 1, strlen(buf), stdout);
  free(buf);
  
  current_col += (buflen - 1); 
}

Note: 
This variant of original function uses vsnprintf and vsprintf instead of vasprintf. Usage and freeing allocation of memory related to "buf" has been modified correspondingly. "fputc" and "fwrite" are used instead of "putchar" and "fputs", which offers a more explicit avoidance of possible IO errors even though underly semantics kept the same. And appending "fflush(stdout);" after "putc" function can make sure instant output for character wise writing. Finally, the calculation of "current_col" also subtracts by 1 because buflen considers the '\0' character as per vsnprintf formulates.