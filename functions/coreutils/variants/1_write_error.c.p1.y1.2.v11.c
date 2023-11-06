Variant 1:

void write_error(void)
{
    int savedErrno = errno; /* renamed variable */
    fflush(stdout);         /* no change */
    clearerr(stdout);       /* no change */
    error(EXIT_FAILURE, savedErrno, _("write error")); /* using variable with new name */
}


Variant 2:

void write_error(void)
{
    fflush(stdout);
    int errno_copy = errno; /* changed variable declaration position & name */
    clearerr(stdout);
    error(EXIT_FAILURE, errno_copy, _("write error"));
}


Variant 3:

void write_error(void)
{
    fflush(stdout);
    clearerr(stdout);
    int latestErrno = errno; /* changed variable declaration position & name */
    error(EXIT_FAILURE, latestErrno, _("write error")); /* using variable with new name */
}
