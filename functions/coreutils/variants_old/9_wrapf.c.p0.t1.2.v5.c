wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args); // silently failing in case of error
  buf = (char *) malloc (sizeof (char) * (buflen+1));

  vsprintf (buf, message, args);
  va_end (args);

  if ((buflen == -1) || (buf == NULL)) // fail more gracefully, freeing resources before exiting
    {
      free(buf);
      exit (1); 
    }

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          fputs("\n", stdout); // replaced putchar('\n') with fputs("\n", stdout)
          current_col = 0;
        }
      else
        {
          fputs(" ", stdout); // replaced putchar(' ') with fputs(" ", stdout)
          current_col++;
        }
    }

  fprintf (stdout, "%s", buf); // replaced fputs (buf, stdout) with fprintf (stdout, "%s", buf)
  free (buf);
  current_col += buflen;
}