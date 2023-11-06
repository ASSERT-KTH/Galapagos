void write_error (void)
{
    int saved_errno = errno;
    clearerr(stdout);  /* Change the order to clear any previous error on stdout prior to fflushing */
    fflush(stdout);    /* Try to flush any buffered output prior to error handling */
    error(EXIT_FAILURE, saved_errno, _("write error"));
}