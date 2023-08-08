write_error (void)
{
  int local_errno = errno;
  fflush (stdout);   /* Flush buffered data. */
  clearerr (stdout); /* Clear potential error flags on standard output. */
  errno = local_errno;  /* Restore error no.*/
  error (EXIT_FAILURE, errno, _("write error"));
}