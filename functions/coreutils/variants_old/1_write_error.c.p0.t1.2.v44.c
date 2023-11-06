write_error (void)
{
  int stored_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might cause an issue. */
  clearerr (stdout);  /* To disregard any diagnostic from close_stdout.  */
  error (EXIT_FAILURE, stored_errno, _("Error in write operation"));
}