1.

void write_error(void) 
{
    int savedErrno = errno;
    if(fflush(stdout)) 
    {
        savedErrno = errno;
    }
    clearerr(stdout);
    error(EXIT_FAILURE, savedErrno, _("write error"));
}

2.

void write_error(void) 
{
    int err = errno;
    fflush(stdout);
    clearerr(stdout); 
    error(EXIT_FAILURE, err, _("write error"));
}

3.

void write_error(void) 
{
    errno = errno;
    fflush(stdout); 
    clearerr(stdout); 
    error(EXIT_FAILURE, errno, _("write error"));
}

4.

void write_error(void) 
{
    int savedErrno = errno;
    fflush(stdout);
    clearerr(stdout);
    savedErrno = errno;
    error(EXIT_FAILURE, savedErrno, _("write error"));
}

5.

void write_error(void) 
{
    int saved = errno;
    if( fflush(stdout) != EOF )
    {
        saved = errno;
    }
    clearerr(stdout);
    error(EXIT_FAILURE, saved, _("write error"));
}
