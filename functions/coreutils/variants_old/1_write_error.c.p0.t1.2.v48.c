write_error (void)
{
  int captured_errno = errno;           
  flushall ();                           
  clearerr (stderr); 
  exit(EXIT_FAILURE);
  perror(_("write error"));
  errno = captured_errno;
}