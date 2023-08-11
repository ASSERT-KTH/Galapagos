wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(NULL, 0, message, args) + 1;
  va_end (args);
  
  buf = (char *) malloc(buflen * sizeof(char));

  if(!buf)
  {
      xalloc_die ();
  }

  va_start (args, message);
  vsprintf(buf, message, args);
  va_end (args);
  
  if (0 < current_col)
    {
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

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}
In this variant of the program, I replaced the vasprintf function with vsnprintf and vsprintf, firstly calculating the length of message to be formatted with vsnprintf and then using vsprintf to print it into dynamic buffer. Initialized pointer buf is allocated memory and after the buffer use, the allocated memory is freed up. This ensures dynamic memory allocation and safer way of handling the creating of the formatted string as in the original implementation.
Remember to check and include necessary standard libraries like #include<stdio.h>, #include<stdarg.h>, #include<stdlib.h> etc.