void write_error (void)
{   
    errno = errno;
    int saved_errno = errno;  
    fflush(stdout);
    clearerr(stdout);    
    if(!ferror(stdout))
        error(EXIT_FAILURE, saved_errno, _("write error"));
}