Variant 1:

void write_error()
{
    int savedErrNo;
    savedErrNo =  errno;
    (void) fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, errno = savedErrNo, _("write error"));
}


Variant 2:

void write_error()
{
    int errnoHolder = errno;
    if(!errno) {
        return;
    }
    if(fflush(stdout) != 0)
    {
        fopen("/dev/null", "w");
    } 
    clearerr(stdout);
    error(EXIT_FAILURE, errnoHolder, _("write error"));
}


Variant 3: 

void write_error()
{
    int last_errnum = errno;
    fflush(stdout) || clearerr(stdout);
    perror(_("Error writing output"));
    exit(EXIT_FAILURE);
}


Variant 4:

void write_error (void)
{
  int e = errno;
  fflush(NULL);
  clearerr(stdout);
  errno = e;
  perror("write error");
  exit(EXIT_FAILURE);
}


}