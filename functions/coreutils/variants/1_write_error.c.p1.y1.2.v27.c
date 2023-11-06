Variant 1:

void write_error (void)
{
  int saved_errno = errno;
  clearerr (stdout);
  fflush (stdout);  
  error (EXIT_FAILURE, saved_errno, _("write error"));
}

Variant 2:

void write_error(void)
{
  int errnoHolder = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errnoHolder, _("write error"));
}

Variant 3:

void write_error(void)
{
  int temp_err = errno;
  clearerr(stdout);
  fflush(stdout);
  error(EXIT_FAILURE, temp_err, _("write error"));
}

Variant 4:

void write_error (void)
{
  fflush (stdout);
  int saved_errno = errno;
  clearerr (stdout);
  error (EXIT_FAILURE, saved_errno, _("write error"));
}
