Variant 1:

void write_error (void)
{
  int saved_errno_unknown = errno;
  fflush (stdout);    
  clearerr (stdout);    
  error (EXIT_FAILURE, saved_errno_unknown, _("write error"));
}


Variant 2:

void write_error (void)
{
  int errno_tmp = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, errno_tmp, _("write error"));
}


Variant 3:

void write_error (void)
{
  int errno_saved = errno;
  fflush (stdout);     
  clearerr (stdout);      
  error (EXIT_FAILURE, errno_saved, _("write error"));
}


Variant 4:

void write_error (void)
{
  int my_errno = errno;
  fflush (stdout);     
  clearerr (stdout);     
  error (EXIT_FAILURE, my_errno, _("write error"));
}
