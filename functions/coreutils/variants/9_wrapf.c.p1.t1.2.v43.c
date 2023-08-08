wrapf (char const *message,...)
{
  va_list l_args;
  char *p_buf;
  int n_buflen;

  va_start (l_args, message);
  n_buflen = vasprintf (&p_buf, message, l_args);
  va_end (l_args);

  if (n_buflen < 0)
    exit(EXIT_FAILURE); //Changed from xalloc_die() to standard exit() function.

  if (0 < current_col)
    {
      int d = max_col - current_col;
      if ( d <= n_buflen)
        {
          printf ("\n");
          current_col = 0;
        }
      else
        {
          printf (" ");
          current_col++;
        }
    }

  int write_status = fputs (p_buf, stdout);
  if (write_status == EOF) //Adding a valuation if fputs is successful
    fprintf(stderr, "Error writing to stdout\n");

  free (p_buf);
  current_col += n_buflen;
}