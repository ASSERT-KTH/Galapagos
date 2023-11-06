Variant 1:

void write_error (void) 
{
  int errno_bk = errno;
  (void)fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errno_bk, "write error");
}


Variant 2:

void write_error (void)
{
  int err=saved_errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, err, "write error");
}


Variant 3:                                                                    

void write_error (void)
{
  int errno_temp = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errno_temp, _("write error"));
}


Variant 4:                                                                    

void write_error (void)
{
  int e = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, e, _("write error"));
}


Variant 5:                                                                    

void write_error (void)
{
  int saved_errno_copy = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, saved_errno_copy, _("write error"));
}
