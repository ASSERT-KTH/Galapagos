1) Code transformation with altered order of statements:

write_error (void)
{
  fflush (stdout);
  int saved_errno = errno;
  clearerr (stdout); 
  error (EXIT_FAILURE, saved_errno, _("write error"));
}


2) Code transformation with local variables:

write_error (void)
{
  int errno_copy = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, errno_copy, _("write error"));
}


3) Code transformation with compound statement:

write_error (void)
{
  int copy_errno = errno; fflush (stdout); clearerr (stdout);
  error (EXIT_FAILURE, copy_errno, _("write error"));
}


4) Code transformation using fclose instead of fflush:

write_error (void)
{
  int saved_errno = errno;
  fclose(stdout);
  open_stdout();
  error (EXIT_FAILURE, saved_errno, _("write error"));
  open_end(stdout);
}


Please note that these transformations depend on associated functionalities of your program and system behaviors. You might need to ensure that you have the necessary permissions (particularly for the latter mentioned transformation) and the proper environment to replicate the exact functionality of the original function. Supposed external function like _() for gettext, error() is properly linked.