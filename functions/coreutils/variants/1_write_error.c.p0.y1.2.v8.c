void write_error (void)
{
    int error_number = errno;
    fflush (stdout);    // Nothing in buffer to cause an error.
    clearerr (stdout);  // Stop superfluous diagnostic info from close_stdout.
    error (EXIT_FAILURE, error_number, _("write error"));
}