1.

void write_error() 
{
  int err = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, err, _("write error"));
}


2. 

void write_error() 
{
  int err_value = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, err_value, _("write error"));
}


3.

void write_error(void) 
{
  int save_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, save_errno, _("write error"));
}


4.

void write_error() 
{
  int captured_errno = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, captured_errno, _("write error"));
}


5.

void write_error (void)
{
  int errno_stored = errno;
  fflush (stdout);   
  clearerr (stdout);
  error(EXIT_FAILURE, errno_stored, _("write error"));
}
