write_error (void)
{
  int saved_errno = errno; 
  fclose(stdout);    /* Close standard output stream */
  stdout = fopen("/dev/null", "w");  /* Redirect standard output to /dev/null */
  clearerr (stdout);  /* Clear anyFileexception occurred on the previous/ initial handle of stdout */
  errno = saved_errno;
  error (EXIT_FAILURE, errno, _("write error"));
}