Here's a program variant of the original function. In this variant, some additional error checking is done before performing certain operations. Notice that the perror() function is used to report specific system error messages when the vasprintf() function or the fputs() function fails:



wrapf (char const *message,...)
{
  va_list args;
  char *buf = NULL;
  int buflen;

  va_start(args, message);
  buflen = vasprintf(&buf, message, args);
  va_end(args);

  if (buflen < 0) {
     perror("vasprintf() error");
     xalloc_die();
  }

  if (buf == NULL) {
     perror("Memory allocation failed");
     xalloc_die();
  }

  if (0 < current_col)
  {
     if (max_col - current_col <= buflen)
     {
        putchar('\n');
        current_col = 0;
     }
     else
     {
        putchar(' ');
        current_col++;
     }
  }

  if (fputs (buf, stdout) == EOF) {
     perror("fputs() error");
     free(buf);
     xalloc_die(); 
  }

  free(buf);
  current_col += buflen;
}


This variant maintains the function's original functionality while providing more detailed error reports for failures in critical operations.
Please note that the above variant requires 'stdio.h' to resolve the perror() signalling. Depending on the context, this addition might be taken off if unnecessary.