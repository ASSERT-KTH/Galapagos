write_error(void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  if (saved_errno != 0)
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else
  {
    printf("%s\n", "There is no write error");
    exit (EXIT_SUCCESS);
  }
}