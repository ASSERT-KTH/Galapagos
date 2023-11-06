1. Just rearranging the lines.


write_error (void)
{
  clearerr (stdout);
  int saved_errno = errno;
  error (EXIT_FAILURE, saved_errno, _("write error"));
  fflush (stdout);
}


2. Changing the variables used 


write_error (void)
{
  int err_num = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, err_num, _("write error"));
}


3. Rearranging and Changing the variables 


write_error (void)
{
  clearerr (stdout);
  int error_num = errno;
  error (EXIT_FAILURE, error_num, _("write error"));
  fflush (stdout);
}
 

4. Changing the exit failure mode


write_error (void)
{
  int saved_errno = errno;
  error (EXIT_HALT, saved_errno, _("write error"));
  clearerr (stdout);
  fflush (stdout);
}


5. Changing the ordering of error reporting and flushing stdout 


write_error (void)
{
  int saved_errno = errno;
  error (EXIT_FAILURE, saved_errno, _("write error"));
  fflush (stdout);
  clearerr (stdout);
}
