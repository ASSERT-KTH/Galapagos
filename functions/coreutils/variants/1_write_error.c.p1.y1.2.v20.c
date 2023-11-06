Variant 1:

void write_error(void) 
{
    int captured_errno = errno;
    fflush(stdout);     
    clearerr(stdout);
    error(EXIT_FAILURE, captured_errno, _("write error"));
}


Variant 2:

void write_error(void)
{
    int temporary_errno = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, temporary_errno, _("write error"));
}


Variant 3:

void write_error(void) 
{
    int cached_errno = errno;
    fflush(stdout);    
    clearerr(stdout);
    error(EXIT_FAILURE, cached_errno, _("write error"));
}


Variant 4:

void write_error(void) 
{
  int stored_errno = errno;
  fflush(stdout);       
  clearerr(stdout);
  error(EXIT_FAILURE, stored_errno, _("write error"));
}
