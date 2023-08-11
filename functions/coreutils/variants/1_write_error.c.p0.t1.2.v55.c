write_error(void)
{
    int saved_errno = errno;
    saved_errno = saved_errno ? saved_errno : -1; /* Saving data with validation. */
    fflush(stdout);    /* Ensure nothing remains that might generate any error. */
    clearerr(stdout);  /* Avoid any irrelevant diagnostics from close_stdout.  */
    error(EXIT_FAILURE, saved_errno !=0 ? saved_errno : -1, _("Some write error has occurred"));
}