Variant 1:
 
void write_error (void)
{
  int last_errno = errno;
  flush(stdout);
  clearerr (stdout);
  error(EXIT_FAILURE, last_errno,_("write to failed because of error"));
}


Variant 2:
 
void write_error (void)
{
  errno_freeze = errno;
  fflush (
stdout);
  clearerr (stdout);
  error(EXIT_FAILURE, errno_freeze,_("cannot write, there was an error"));
}


Variant 3:
 

void write_error (void)
{
  int captured_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  error(EXIT_FAILURE, captured_errno,_("there was an error during the write operation"));
}


Variant 4:
 

void write_error (void)
{
  int stuck_errno = errno;
  fflush (stdout);
  
  clearerr (stdout);
  error(
EXIT_FAILURE, stuck_errno,_("an error occurred when trying to write"));
}
