Variant 1:

write_error (void)
{
  int local_errno = errno;
  clearerr (stdout);
  fflush (stdout);
  error (EXIT_FAILURE, local_errno, _("write error"));
}


Variant 2:

write_error (void)
{
  int error_no = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, error_no, _("write error"));
}


Variant 3:

write_error (void)
{
  int er_no = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, er_no, _("write error"));  
}


Variant 4:

write_error (void)
{
  int recent_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, recent_errno, _("write error"));
}


Variant 5:

write_error (void)
{
  int saved_errno_for_write = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, saved_errno_for_write, _("write error"));
}
