write_error (void)
{
  int saved_errno = errno;
  errno = 0;  /* Reset the errno before performing other operations */
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  if (ferror(stdout)) /* Check for errors occurred in previous operation if any. */
  {
    clearerr (stdout);  /* Clear out the error state if any error occurred */
  }
  errno = saved_errno; /* reset the saved errno from before */
  error (EXIT_FAILURE, saved_errno, _("write error")); /* report the error */
}