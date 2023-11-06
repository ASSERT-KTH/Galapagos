write_error(void)
{
    int older_err = errno;
    fflush (stderr);    /* Change: Ensure nothing buffered that might induce an error. */
    clearerr (stderr);  /* Change: To avoid extraneous diagnostic from close_stderr.  */
    error (EXIT_FAILURE, older_err, _("write error"));
}