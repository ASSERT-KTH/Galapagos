Here's a version of the function that adds some debug-style logging confirmation of action to a text file. Comments have been added to better explain additions. Note that while this literal approach specifically satisfies your defined parameters, it could: be viewed as harmful because larger or more critical programs or systems would potentially write out log files of a huge size due to the frequency at which the function is likely to be called.

wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
 
  /* Preparation for File based debugging */
  FILE *fptr;
  fptr = fopen("debug.txt","a");
  if(fptr == NULL)
  {
    printf("Error!");  
    exit(1);        
  }

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  fprintf(fptr, "DEBUG: running vasprintf.\n");
   
  if (buflen < 0)
  {
    xalloc_die ();
    fprintf(fptr, "ERROR: Allocation error called.\n");
  }

  if (0 < current_col)
  {
    if (max_col - current_col <= buflen)
    {
      putchar ('\n');
      current_col = 0;
      fprintf(fptr, "DEBUG: Printing newline due to max columns.\n");
    }
    else
    {
      putchar (' ');
      current_col++;
      fprintf(fptr, "DEBUG: Printing space bar due to non-empty current_col.\n");
    }
  }

  fputs (buf, stdout);
  fprintf(fptr, "DEBUG: Writing buffer text to stdout.\n");
  
  free (buf);
  current_col += buflen;

  fprintf(fptr, "DEBUG: Memore freeing and current_column updated\n");
  
  //must ensure the file is closed after writing to it to prevent leakage
  fclose(fptr);
}