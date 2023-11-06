Variant 1:

void write_error (void)
{
  int backup_error_number = errno;
  fflush (stdout);   
  clearerr (stdout); 
  error (EXIT_FAILURE, backup_error_number, _("write error"));
}

Variant 2:

void write_error (void)
{
  int old_errno = errno;
  fflush (stdout);   
  clearerr (stdout);
  error (EXIT_FAILURE, old_errno, _("write error"));
}

Variant 3:

void write_error (void)
{
  int errorCode = errno;
  fflush (stdout);   
  clearerr (stdout);
  error (EXIT_FAILURE, errorCode, _("write error"));
}

Variant 4:

void write_error (void)
{
  int temp_errno = errno;
  fflush (stdout); 
  clearerr (stdout);
  error (EXIT_FAILURE, temp_errno, _("write error"));
}
