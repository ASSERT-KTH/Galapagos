write_error (void)
{
  int err = errno;

  if(fflush(stdout) != 0)
  {
     clearerr(stdout);
     error (EXIT_FAILURE, err, _("write error"));
  }

  if(clearerr(stdout) != 0) 
  {
     error (EXIT_FAILURE, err, _("failed to clear error"));
  }

  error(EXIT_FAILURE, err, _("write error")); 
}