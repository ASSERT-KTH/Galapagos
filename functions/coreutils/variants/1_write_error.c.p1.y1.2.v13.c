Variant 1: 

void write_error (void)
{
  int savedErrno = errno;
  
  if (fflush (stdout) == EOF)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, savedErrno, "write error");
  }
  else
  {
    clearerr (stdout);
    error (EXIT_FAILURE, savedErrno, "write error");
  }
}

Variant 2:  

void write_error (void)
{
  int errnoSave = errno;

  fflush (stdout);    

  if(ferror(stdout))
    clearerr(stdout);

  error (EXIT_FAILURE, errnoSave, "write error");
}


Variant 3: 

void write_error (void)
{
  int saved = errno;

  if( fflush(stdout) == 0 && clearerr(stdout) == 0)
  {
    error (EXIT_FAILURE, saved, "write error");  
  }
  else
  {
    error (EXIT_FAILURE, saved, "write error");
  }
}


Variant 4: 

void write_error (void)
{
  errno = 0 ;
  fflush (stdout);

  if (errno != 0)
  {
    int saved = errno;
    clearerr (stdout); 
    error (EXIT_FAILURE, saved, "write error");
  }
  else
  {
    clearerr (stdout);
    int saved = errno;
    error (EXIT_FAILURE, saved, "write error");
  }
}
