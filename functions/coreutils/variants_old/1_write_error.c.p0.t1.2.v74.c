write_error (void)
{
    int last_err = errno;
    fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
    clearerr (stderr);  /* To stop extraneous diagnostic from close_stdout.  */
    error (EXIT_FAILURE, last_err, _("error on write"));
}