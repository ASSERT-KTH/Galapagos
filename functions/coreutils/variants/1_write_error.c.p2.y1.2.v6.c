write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);      /* Flush everything from buffer. If error inducing conditions existed, remove them */
  if (ferror (stdout))  /* Check if error has occurred. */
  {              
    clearerr (stdout);  /* If error has occurred, clear it */
  } 
  error (EXIT_FAILURE, saved_errno, _("write error"));
}