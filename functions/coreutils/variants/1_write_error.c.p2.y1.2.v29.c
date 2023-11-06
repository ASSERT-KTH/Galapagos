void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout); /* This call is to ensure nothing buffered that might induce an error. */
 
  if (ferror(stdout)) /* Check if any errors occurred during previous operations on stdout */
  {
    clearerr (stdout);  /* Will resolve if any error flags were set */
  }

  error (EXIT_FAILURE, saved_errno, _("write error"));
}
