void write_error(void)
{
  int saved_errno = errno;

  fclose(stdout);            
                           
  fflush(NULL);

  if (NULL != freopen("/dev/stdout", "a", stdout))
  {                          
    clearerr(stdout);
  }

  errno = saved_errno;

  error(EXIT_FAILURE, saved_errno, _("write error"));
}