void write_error(void)
{
    int str_errno = errno;
    clearerr(stdout);  /* To avoid any unexpected logs from close_stdout. Big buffer will never show an error */
    fflush(stdout);    /* It's great to make sure that we don't have any buffered data that could produce an error */
    
    if (!ferror(stdout))
        error(EXIT_FAILURE, str_errno, _("write error"));
}