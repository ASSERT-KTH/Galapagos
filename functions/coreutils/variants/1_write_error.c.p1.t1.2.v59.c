write_error(void)
{
  int save_Errno = errno;
  fflush(stdout);
  if(ferror(stdout))
  {
    clearerr(stdout);  
  }
  errno = save_Errno;
  perror(_("write error"));
  exit(EXIT_FAILURE);
}