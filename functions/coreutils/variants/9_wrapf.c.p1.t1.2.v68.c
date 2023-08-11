The following code is a variant of the original function. It emphasizes more on the error handling and manages memory more carefully, while preserving the functions original signing and behavior. Also, it also checks whether fwrite has succeeded or not.


wrapf (char const *message,...)
{
  va_list args;
  char *buf = NULL;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf,message,args);
  va_end (args);

  if(buflen < 0 || !buf)
  {
   free(buf);
   xalloc_die ();
  }

  if(0 < current_col)
  {
    if(max_col - current_col <= buflen)
    {
        if (putchar('\n') == EOF) 
        {
            free(buf);
            xalloc_die ();
        }

        current_col = 0;
    }
    else
    {
        if (putchar(' ') == EOF)
        {
            free(buf);
             xalloc_die ();
         }

       current_col++;
     }
  }

  if (fputs(buf,stdout) == EOF) 
  {
    free(buf);
    xalloc_die ();
  }

  free(buf);
  current_col += buflen;

}
