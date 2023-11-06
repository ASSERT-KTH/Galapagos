1) Using early return to check error condition:

void write_error() 
{
  int saved_errno = errno;
  if(saved_errno == 0) return;
  
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, saved_errno, _("write error"));
}


2) Change the order for better abstraction:

void write_error(void) 
{
  int saved_errno = errno;
  error(EXIT_FAILURE, saved_errno, _("write error"));
  fflush(stdout);
  clearerr(stdout);
}


3) useMemoization to save errno:

void write_error(void) 
{
  static int saved_errno = -1;
  if(saved_errno == -1)
  {
    saved_errno = errno;
  }
  
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, saved_errno, _("write error"));
}


4) Using Conditional operator:

void write_error(void) 
{
  int saved_errno = errno;
  (saved_errno == errno ? fflush(stdout) : errno);
  clearerr(stdout);
  error(EXIT_FAILURE, saved_errno, _("write error"));
}
