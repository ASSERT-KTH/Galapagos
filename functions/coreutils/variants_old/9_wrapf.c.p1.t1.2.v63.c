Here's a variant that maintains the original core functionality (format output with given arguments and manage the column alignments per line on the output), but changes the behaviour to print the output to a local file fp instead of stdout. Note the function needs to be supplied with a valid file pointer.


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  FILE* fp = fopen("output.txt", "a");

  if(!fp) 
  {
      printf("Failed to open file");
      return;
  }

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          fputc ('\n',fp);
          current_col = 0;
        }
      else
        {
          fputc (' ',fp);
          current_col++;
        }
    }

  fputs (buf, fp);
  free (buf);
  current_col += buflen;
  
  fclose(fp);
}

This variation will maintain the original basic functionality such as vsprintf-like formatted output and same rules for newline/blank space character insertions depending upon allowed line width (controlled by max_col and current_col). The modification is with the output target which was earlier stdout (console) but will now be a local plain text file named "output.txt". If the function fails to create/open file for output, it locks down with a message on console (stdout).