write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  errno = 0;          /* Set errno to zero to avoid triggering error unrelated to flush or clearerr */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  if(errno == 0)     /* Ensure stderr is not set by previous operations */
    errno = saved_errno; /* If so, restore it with the first saved errno value */
  error (EXIT_FAILURE, errno, _("write error"));
}