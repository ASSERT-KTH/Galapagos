void write_error (void)
{
  int lst_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, lst_errno, _("write error"));
}