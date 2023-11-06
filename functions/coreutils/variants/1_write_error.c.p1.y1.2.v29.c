Variant 1:

void write_error (void)
{
  int error_num = errno;
  fflush (stdout);   
  clearerr (stdout);  
  error (EXIT_FAILURE, error_num, _("write error"));
}


Variant 2:

void write_error (void)
{
  int errnum = errno;
  fflush(stdout);    
  clearerr(stdout); 
  error (EXIT_FAILURE, errnum, _("write error"));
}


Variant 3:

void write_error(void) 
{
  int savedErrno = errno;
  (void) fflush(stdout); 
  clearerr(stdout);
  error(EXIT_FAILURE, savedErrno, _("write error"));
}


Variant 4:

void write_error (void)
{
  int preserved_errno = errno;
  fflush (stdout); 
  clearerr (stdout); 
  error (EXIT_FAILURE, preserved_errno, _("write error"));
}


Variant 5:

void write_error(void)
{
  int error_code = errno;
  fflush(stdout); 
  clearerr(stdout);
  error(EXIT_FAILURE, error_code, _("write error"));
}
