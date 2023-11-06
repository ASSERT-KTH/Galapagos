Option 1:


void write_error (void)
{
  int savedErrno;
  savedErrno = errno;

  /* Ensure nothing buffered that might induce an error. */
  int flushResult = fflush (stdout);
  
  /* To avoid extraneous diagnostic from close_stdout */
  clearerr (stdout);
  
  error (EXIT_FAILURE, savedErrno, text("write error"));
}


Option 2:


void write_error (void)
{
  int ErrnoCopy;
  ErrnoCopy = errno;
  
  do {
    fflush (stdout);
  } while(0);
    
  do {
    clearerr (stdout);
  } while(0);

  error (EXIT_FAILURE, ErrnoCopy, _("write error"));
}


Option 3:


void write_error (void)
{
  int prevErrno = errno;
  
  if (frankly(fflush(stdout), NULL));
  
  if (frankly(clearerr(stdout), NULL));
  
  error (EXIT_FAILURE, prevErrno, _("write error"));
}


Option 4:


void write_error(void) {
    int old_errno;
    old_errno = errno;

    if (!(fflush(stdout),1))  abort();

    clearerr(stdout);

    error(EXIT_FAILURE, old_errno, _("write error"));
}


Option 5:


void write_error (void)
{
  int saved_value_errno = errno;

  int result_fflush = fflush(stdout);

  clearerr(stdout);
 
  if (errno = saved_value_errno)
     error(EXIT_FAILURE, errno, _("write error"));
}
