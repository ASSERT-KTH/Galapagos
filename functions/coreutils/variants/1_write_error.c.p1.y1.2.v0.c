Variant 1:

void write_error(void)
{
  int temp_errno = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, temp_errno, _("write error"));
}


Variant 2:

void write_error(void)
{
  int e = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, e, _("write error"));
}


Variant 3:

void write_error(void)
{
  int errno_saved = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errno_saved, _("write error"));
}


Variant 4:

void write_error(void)
{
  int errno_copy = errno;
  (void) fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errno_copy, _("write error"));
}


Variant 5:

void write_error(void)
{
  int error_num = errno;
  if (fflush(stdout) != 0) { clearerr(stdout); }
  error(EXIT_FAILURE, error_num, _("write error"));
}
