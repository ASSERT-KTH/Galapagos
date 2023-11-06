void write_error (void)
{
  int error_saved = errno;
 
  fflush(stdout); // getting rid of any buffered stuff that may create an issue.
  clearerr(stdout); // Takes out error if any from stdout
  
  error(EXIT_FAILURE, error_saved, _("write error"));
}