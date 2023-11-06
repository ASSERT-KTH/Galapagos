void write_error (void)
{
    int tmp_errno = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, tmp_errno, _("write error"));
}